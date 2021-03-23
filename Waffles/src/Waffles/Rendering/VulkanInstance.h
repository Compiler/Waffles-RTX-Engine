#pragma once
#include <Waffles/Waffles.h>
#define GLFW_INCLUDE_VULKAN
#include <Waffles/Rendering/Window.h>
#include <Waffles/Startup/Startup.h>
#include <Waffles/Tools/Logging.h>
#include <Waffles/Tools/FileUtils/FileLoader.h>
#include <Waffles/Tools/DebugUtils/VkDebugUtils.h>
#include <cstring>
#include <string>
#include <set>

#ifdef DEBUG_MODE
const bool enableValidationLayers = true;
#else
const bool enableValidationLayers = false;
#endif



#define DEBUG_FUNC(x) INIT_LOG("----\tStarting %s", #x); x; LOG("----\tEnding %s", #x)
namespace Waffles{
    struct OptionalPair{
        uint32_t index;
        bool set = false;
    };
    struct QueueFamilyIndices {
        OptionalPair graphicsFamily;
        OptionalPair presentationFamily;
        
        bool isComplete() {
            return graphicsFamily.set && presentationFamily.set;
        }
    };

    struct SwapChainSupportDetails {
        VkSurfaceCapabilitiesKHR capabilities;
        std::vector<VkSurfaceFormatKHR> formats;
        std::vector<VkPresentModeKHR> presentModes;
    };

    class VulkanInstance{

        private:
            VkInstance _vulkanInstance;
            VkPhysicalDevice _physicalDevice;
            VkDevice _logicalDevice;
            VkQueue _graphicsQueue, _presentationQueue;
            VkSurfaceKHR _surface;
            VkDebugUtilsMessengerEXT _debugMessenger;
            VkSwapchainKHR _swapChain;
            std::vector<VkImage> _swapChainImages;
            std::vector<VkImageView> _swapChainImageViews;
            VkFormat _swapChainImageFormat;
            VkExtent2D _swapChainExtent;
            VkPipelineLayout _pipelineLayout;
            VkRenderPass _renderPass;
            VkPipeline _graphicsPipeline;
            std::vector<VkFramebuffer> _swapChainFramebuffers;
            VkCommandPool _graphicsCommandPool;

            void _createInstance(const char* appName, const char* engineName);
            void _createDebugMessenger();
            bool _validatationLayersAssert();
            void _setPhysicalDevice();
            bool _isRTXEnabledGPU(VkPhysicalDevice);
            void _createLogicalDevice();
            void _createSurface(GLFWwindow* window);
            bool _deviceSupportsExtensions(VkPhysicalDevice device);
            void _createSwapChain(GLFWwindow* window);
            void _createImageViews();
            void _createRenderPass();
            void _createGraphicsPipeline();
            void _createFrameBuffers();
            void _createGraphicsCommandPool();


            VkShaderModule _createShaderModule(const std::vector<char>& code);
            SwapChainSupportDetails _querySwapChainSupport(VkPhysicalDevice device);
            VkSurfaceFormatKHR _chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
            VkPresentModeKHR _chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
            VkExtent2D _chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities, GLFWwindow* window);

            QueueFamilyIndices _getQueueFamilies(VkPhysicalDevice);

            const std::vector<const char*> _validationLayers = {
                "VK_LAYER_KHRONOS_validation"
            };

            const std::vector<const char*> _deviceExtensions = {
                VK_KHR_SWAPCHAIN_EXTENSION_NAME,
                VK_NV_RAY_TRACING_EXTENSION_NAME,
                //VK_KHR_ACCELERATION_STRUCTURE_EXTENSION_NAME, 
                //VK_KHR_RAY_TRACING_PIPELINE_EXTENSION_NAME, 
                //VK_KHR_MAINTENANCE3_EXTENSION_NAME,
                //VK_KHR_PIPELINE_LIBRARY_EXTENSION_NAME, 
                //VK_KHR_DEFERRED_HOST_OPERATIONS_EXTENSION_NAME, 
                //VK_KHR_BUFFER_DEVICE_ADDRESS_EXTENSION_NAME
            };
            const std::vector<const char*> _instanceExtensions = {
                //VK_KHR_RAY_TRACING_PIPELINE_EXTENSION_NAME

            };

        public:

            void load(GLFWwindow* window);


            void unload();


        private:
            std::vector<const char*> getRequiredExtensions() {
                uint32_t glfwExtensionCount = 0;
                const char** glfwExtensions;
                glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

                std::vector<const char*> extensions(glfwExtensions, glfwExtensions + glfwExtensionCount);

                if (enableValidationLayers) {
                    LOG("Added debug tools ");
                    extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
                }

                return extensions;
        }


            static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData) {
                if(messageSeverity == VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT) {
                    WARN("validation layer: %s", pCallbackData->pMessage);
                }
                if(messageSeverity > VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT) {
                    NON_FATAL_ERROR("validation layer: %s", pCallbackData->pMessage);
                }
                return VK_FALSE;
            }

            void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo) {
                createInfo = {};
                createInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
                createInfo.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
                createInfo.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
                createInfo.pfnUserCallback = debugCallback;
            }

            VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger) {
                auto func = (PFN_vkCreateDebugUtilsMessengerEXT) vkGetInstanceProcAddr(instance, "vkCreateDebugUtilsMessengerEXT");
                if (func != nullptr) {
                    return func(instance, pCreateInfo, pAllocator, pDebugMessenger);
                } else {
                    return VK_ERROR_EXTENSION_NOT_PRESENT;
                }
            }

            void DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator) {
                auto func = (PFN_vkDestroyDebugUtilsMessengerEXT) vkGetInstanceProcAddr(instance, "vkDestroyDebugUtilsMessengerEXT");
                if (func != nullptr) {
                    func(instance, debugMessenger, pAllocator);
                }
            }

            

        };


}
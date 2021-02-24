#pragma once
#include <Waffles.h>
#define GLFW_INCLUDE_VULKAN
#include <Rendering/Window.h>
#include <Startup/Startup.h>
#include <Tools/Logging.h>
#include <cstring>
#include <string>
//#include <optional>
namespace Waffles{
    struct OptionalPair{
        uint32_t index;
        bool set = false;
    };
    struct QueueFamilyIndices {
        //std::optional<uint32_t> graphicsFamily;
        OptionalPair graphicsFamily;
        
        bool isComplete() {
            return graphicsFamily.set;
        }
    };

    class VulkanInstance{

        private:
            VkInstance _vulkanInstance;
            VkPhysicalDevice _physicalDevice;
            VkDevice _logicalDevice;
            VkQueue _graphicsQueue;
            bool _activateLayers = false;
            void _validatationLayersAssert();
            void _setPhysicalDevice();
            bool _isRTXEnabledGPU(VkPhysicalDevice);
            void _createLogicalDevice();
            QueueFamilyIndices _getQueueFamilies(VkPhysicalDevice);

            const std::vector<const char*> _validationLayers = {
                "VK_LAYER_KHRONOS_validation"
            };

        public:

            void load();


            void unload();

    };

}
#include "VulkanInstance.h"

namespace Waffles{

    void VulkanInstance::load(){

        _vulkanInstance = Startup::createVKInstance("Waffles-RTX-PBR", "Waffles");
        _validatationLayersAssert();
        _setPhysicalDevice();
    }

    void VulkanInstance::_validatationLayersAssert(){
        uint32_t layerCount;
        vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

        std::vector<VkLayerProperties> availableLayers(layerCount);
        vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());
        bool validationLayersSupported = false;
        const std::vector<const char*> _validationLayers = {"VK_LAYER_KHRONOS_validation"};
        for (const char* layerName : _validationLayers) {
            bool layerFound = false;

            for (const auto& layerProperties : availableLayers) {
                if (strcmp(layerName, layerProperties.layerName) == 0) {
                    layerFound = true;
                    break;
                }
            }

            if (!layerFound) {
                validationLayersSupported = false;
            }
        }

        validationLayersSupported = true;

        #ifdef DEBUG_MODE
            if(!validationLayersSupported){
                ERROR("Debug mode activated but couldn't initialize validation layers");
            }
        #else
            DEBUG("Validation layers initialized");
        #endif


    }


    void VulkanInstance::_setPhysicalDevice(){
        VkPhysicalDevice physDev = VK_NULL_HANDLE;
        uint32_t devCount = 0;
        vkEnumeratePhysicalDevices(_vulkanInstance, &devCount, nullptr);
        LOG("Num devices: %d", devCount);
        if(devCount == 0){
            ERROR("No GPUs found ");
        }
        std::vector<VkPhysicalDevice> devices(devCount);
        vkEnumeratePhysicalDevices(_vulkanInstance, &devCount, devices.data());
        
    }

    void VulkanInstance::unload(){
        UNLOAD_LOG("Unloading VulkanInstance...");
        vkDestroyInstance(_vulkanInstance, nullptr);

    }
}
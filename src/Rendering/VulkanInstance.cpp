#include "VulkanInstance.h"

namespace Waffles{

    void VulkanInstance::load(){

        _vulkanInstance = Startup::createVKInstance("Waffles-RTX-PBR", "Waffles");
        _validatationLayersAssert();
        _setPhysicalDevice();
    }



    bool VulkanInstance::_isRTXEnabledGPU(VkPhysicalDevice dev){
        VkPhysicalDeviceProperties deviceProperties;
        VkPhysicalDeviceFeatures deviceFeatures;
        vkGetPhysicalDeviceProperties(dev, &deviceProperties);
        vkGetPhysicalDeviceFeatures(dev, &deviceFeatures);
        QueueFamilyIndices indices = getQueueFamilies(dev);
        return indices.isComplete();
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

        for (const auto& device : devices) {
            if (_isRTXEnabledGPU(device)) {
                _physicalDevice = device;
                LOG("RTX Enabled device set");
                break;
            }
        }

        if (_physicalDevice == VK_NULL_HANDLE) {
            ERROR("No RTX Enabled GPU support found.");
        }
        
    }

    QueueFamilyIndices VulkanInstance::getQueueFamilies(VkPhysicalDevice device){
        QueueFamilyIndices indices;
        uint32_t queueFamilyCount = 0;
        vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, nullptr);

        std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
        vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, queueFamilies.data());
        int i = 0;
        for (const auto& queueFamily : queueFamilies) {
            if (queueFamily.queueFlags & VK_QUEUE_GRAPHICS_BIT){
                indices.graphicsFamily = i;
                indices.gf_set = true;
            }
            if(indices.isComplete()) break;
            i++;
        }
        return indices;
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

    void VulkanInstance::unload(){
        UNLOAD_LOG("Unloading VulkanInstance...");
        vkDestroyInstance(_vulkanInstance, nullptr);

    }
}
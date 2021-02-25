#include "VulkanInstance.h"

namespace Waffles{

    void VulkanInstance::load(GLFWwindow* window){
        _vulkanInstance = Startup::createVKInstance("Waffles-RTX-PBR", "Waffles");
        LOG("Vulkan Instance retreived");
        DEBUG_FUNC(_validatationLayersAssert());
        DEBUG_FUNC(_createSurface(window));
        DEBUG_FUNC(_setPhysicalDevice());
        DEBUG_FUNC(_createLogicalDevice());
    }



    bool VulkanInstance::_isRTXEnabledGPU(VkPhysicalDevice dev){
        VkPhysicalDeviceProperties deviceProperties;
        VkPhysicalDeviceFeatures deviceFeatures;
        vkGetPhysicalDeviceProperties(dev, &deviceProperties);
        vkGetPhysicalDeviceFeatures(dev, &deviceFeatures);
        LOG("Testing: %s", deviceProperties.deviceName );

        QueueFamilyIndices indices = _getQueueFamilies(dev);
        return indices.isComplete() && deviceFeatures.geometryShader && deviceProperties.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU;
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
                //break;
            }
        }

        if (_physicalDevice == VK_NULL_HANDLE) {
            ERROR("No RTX Enabled GPU support found.");
        }
        
    }

    QueueFamilyIndices VulkanInstance::_getQueueFamilies(VkPhysicalDevice device){
        QueueFamilyIndices indices;
        uint32_t queueFamilyCount = 0;
        vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, nullptr);

        std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
        vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, queueFamilies.data());
        
        VkBool32 presentSupport = false;
        
        int i = 0;
        for (const auto& queueFamily : queueFamilies) {
            vkGetPhysicalDeviceSurfaceSupportKHR(device, i, _surface, &presentSupport);
            LOG("HEre");
            if (queueFamily.queueFlags & VK_QUEUE_GRAPHICS_BIT){
                indices.graphicsFamily.index = i;
                indices.graphicsFamily.set = true;
            }
            if (presentSupport) {
                indices.presentFamily.index = i;
                indices.presentFamily.set = true;
            }
            if(indices.isComplete()) break;
            i++;

        }
        return indices;
    }

    void VulkanInstance::_createLogicalDevice(){
        QueueFamilyIndices indices = _getQueueFamilies(_physicalDevice);

        VkDeviceQueueCreateInfo queueCreateInfo{};
        queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
        queueCreateInfo.queueFamilyIndex = indices.graphicsFamily.index;
        queueCreateInfo.queueCount = 1;
        float queuePriority = 1.0f;
        queueCreateInfo.pQueuePriorities = &queuePriority;

        VkPhysicalDeviceFeatures deviceFeatures{};
        VkDeviceCreateInfo createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;

        createInfo.pQueueCreateInfos = &queueCreateInfo;
        createInfo.queueCreateInfoCount = 1;

        createInfo.pEnabledFeatures = &deviceFeatures;

        createInfo.enabledExtensionCount = 0;

        if(_activateLayers){
            createInfo.enabledLayerCount = static_cast<uint32_t>(_validationLayers.size());
            createInfo.ppEnabledLayerNames = _validationLayers.data();
        }else createInfo.enabledLayerCount = 0;

        if (vkCreateDevice(_physicalDevice, &createInfo, nullptr, &_logicalDevice) != VK_SUCCESS) {
            ERROR("failed to create logical device!");
        }else {LOG("Created logical device.");}

        vkGetDeviceQueue(_logicalDevice, indices.graphicsFamily.index, 0, &_graphicsQueue); //retrieve queue handle


    }

    void VulkanInstance::_createSurface(GLFWwindow* window){
        if (glfwCreateWindowSurface(_vulkanInstance, window, nullptr, &_surface) != VK_SUCCESS) {
            ERROR("failed to create window surface!");
        }
    }


    void VulkanInstance::_validatationLayersAssert(){
        uint32_t layerCount;
        vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

        std::vector<VkLayerProperties> availableLayers(layerCount);
        vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());
        bool validationLayersSupported = false;
        LOG("Validation layers size: %d", _validationLayers.size());
        LOG("Validation layers size: %s", _validationLayers.at(0));
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
            _activateLayers = true;
            if(!validationLayersSupported){
                ERROR("Debug mode activated but couldn't initialize validation layers");
            }
        #else
            DEBUG("Validation layers initialized");
        #endif


    }

    void VulkanInstance::unload(){
        UNLOAD_LOG("Unloading VulkanInstance...");
        vkDestroySurfaceKHR(_vulkanInstance, _surface, nullptr);
        vkDestroyDevice(_logicalDevice, nullptr);
        vkDestroyInstance(_vulkanInstance, nullptr);

    }
}
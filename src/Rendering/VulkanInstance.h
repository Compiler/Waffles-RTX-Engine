#pragma once
#include <Waffles.h>
#define GLFW_INCLUDE_VULKAN
#include <Rendering/Window.h>
#include <Startup/Startup.h>
#include <Tools/Logging.h>
#include <cstring>
//#include <optional>
namespace Waffles{

    struct QueueFamilyIndices {
        //std::optional<uint32_t> graphicsFamily;
        uint32_t graphicsFamily;
        bool gf_set = false;
        
        bool isComplete() {
            return gf_set;
        }
    };

    class VulkanInstance{

        private:
            VkInstance _vulkanInstance;
            VkPhysicalDevice _physicalDevice;
            VkDevice _logicalDevice;
            void _validatationLayersAssert();
            void _setPhysicalDevice();
            bool _isRTXEnabledGPU(VkPhysicalDevice);
            QueueFamilyIndices getQueueFamilies(VkPhysicalDevice);

        public:

            void load();


            void unload();

    };

}
#pragma once
#include <Waffles.h>
#define GLFW_INCLUDE_VULKAN
#include <Rendering/Window.h>
#include <Startup/Startup.h>
#include <Tools/Logging.h>
#include <cstring>
#include <optional>
namespace Waffles{
    struct QueueFamilyIndices {
        std::experimental::optional<uint32_t> graphicsFamily;
        
        bool isComplete() {
            return graphicsFamily.has_value();
        }
    };

    class VulkanInstance{

        private:
            VkInstance _vulkanInstance;
            VkPhysicalDevice _physicalDevice;
            void _validatationLayersAssert();
            void _setPhysicalDevice();
            bool _isRTXEnabledGPU(VkPhysicalDevice);
            uint32_t getQueueFamilies(VkPhysicalDevice);

        public:

            void load();


            void unload();

    };

}
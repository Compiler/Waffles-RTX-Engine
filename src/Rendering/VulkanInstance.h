#pragma once
#include <Waffles.h>
#define GLFW_INCLUDE_VULKAN
#include <Rendering/Window.h>
#include <Startup/Startup.h>
#include <Tools/Logging.h>
#include <cstring>
namespace Waffles{


    class VulkanInstance{

        private:
            VkInstance _vulkanInstance;
            VkPhysicalDevice _physicalDevice;
            void _validatationLayersAssert();
            void _setPhysicalDevice();

        public:

            void load();


            void unload();

    };

}
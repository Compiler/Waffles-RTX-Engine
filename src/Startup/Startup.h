#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <Tools/Logging.h>
#include <vector>
namespace Waffles{

    class Startup{
        public:        
            static VkInstance createVKInstance(const char* appName, const char* engineName);
        
    };

}
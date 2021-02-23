#pragma once
#include <Waffles.h>
#define GLFW_INCLUDE_VULKAN
#include <Rendering/Window.h>
#include <Startup/Startup.h>
#include <Tools/Logging.h>
#include <vector>
#include <cstring>
#include <Rendering/VulkanInstance.h>
#include <Tools/Input/InputManager.h>
#include <Tools/Input/GLFWCallbacks.h>
namespace Waffles{

    class EngineCore{

        private:
            Window* _window;
            VulkanInstance _vkInstance;



        public:
            void load();
            void update();
            void render();
            void unload();
            bool isRunning() const {return _window->isRunning();}

    };

}
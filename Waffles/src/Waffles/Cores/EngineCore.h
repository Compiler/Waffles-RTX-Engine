#pragma once
#include <Waffles/Waffles.h>
#define GLFW_INCLUDE_VULKAN
#include <Waffles/Rendering/Window.h>
#include <Waffles/Startup/Startup.h>
#include <Waffles/Tools/Logging.h>
#include <vector>
#include <cstring>
#include <Waffles/Rendering/VulkanInstance.h>
#include <Waffles/Tools/Input/InputManager.h>
#include <Waffles/Tools/Input/GLFWCallbacks.h>
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
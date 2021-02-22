#pragma once
#include <Waffles.h>
#define GLFW_INCLUDE_VULKAN
#include <Rendering/Window.h>
#include <Startup/Startup.h>
#include <Tools/Logging.h>
#include <vector>
#include <cstring>
namespace Waffles{

    class EngineCore{

        private:
            Window* _window;
            VkInstance _vulkanInstance;
            void validatationLayersAssert();

        public:
            void load();
            void update();
            void render();
            void unload();
            bool isRunning() const {return _window->isRunning();}

    };

}
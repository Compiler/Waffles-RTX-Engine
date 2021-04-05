#pragma once
#include <Waffles/Waffles.h>
#define GLFW_INCLUDE_VULKAN
#include <Waffles/Rendering/Window.h>
#include <Waffles/Startup/Startup.h>
#include <Waffles/Tools/Logging.h>
#include <vector>
#include <cstring>
#include <Waffles/Tools/Input/InputManager.h>
#include <Waffles/Tools/Input/GLFWCallbacks.h>

#include <entt/entt.hpp>
#include <entt/entity/registry.hpp>
#include <Waffles/Cores/RenderCore.h>

#include <Waffles/Rendering/Vertex/Vertex.h>

namespace Waffles{

    class EngineCore{

        private:
            Window* _window;
            Waffles::RenderCore _rasterizedCore;



        public:
            void load();
            void update();
            void render();
            void unload();
            inline bool isRunning() const {return _window->isRunning();}

    };

}
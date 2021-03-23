#pragma once
#include <Waffles/Tools/Logging.h>
#include <Waffles/Rendering/VulkanInstance.h>
#include <Waffles/Rendering/Window.h>

namespace Waffles{

    class RenderCore{
        private:
            VulkanInstance _vkInstance;

        public:
            void load(Waffles::Window* windowRef);
            void update();
            void render();
            void unload();

    };

}
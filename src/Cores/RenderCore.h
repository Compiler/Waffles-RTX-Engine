#pragma once
#include <Tools/Logging.h>
#include <Cores/EngineCore.h>

namespace Waffles{

    class RenderCore{
        private:
            Waffles::EngineCore _engineCore;

        public:
            void load();
            void update();
            void render();
            void unload();
            inline bool isRunning() const {return _engineCore.isRunning();}

    };

}
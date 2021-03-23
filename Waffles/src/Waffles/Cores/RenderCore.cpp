#include "RenderCore.h"
namespace Waffles{

    void RenderCore::load(Waffles::Window* windowRef){
        INIT_LOG("RenderCore Loading...");

        _vkInstance.load(windowRef->getWindow());

    }

    void RenderCore::update(){
        

    }   

    void RenderCore::render(){
        _vkInstance.render();
    }

    void RenderCore::unload(){
        UNLOAD_LOG("Unloading RenderCore...");

    }

}

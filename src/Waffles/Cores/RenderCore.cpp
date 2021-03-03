#include "RenderCore.h"
namespace Waffles{

    void RenderCore::load(){
        INIT_LOG("RenderCore Loading...");
        _engineCore.load();
    }

    void RenderCore::update(){
        _engineCore.update();
        glfwPollEvents();
        

    }   

    void RenderCore::render(){
        _engineCore.render();

    }

    void RenderCore::unload(){
        _engineCore.unload();

    }

}

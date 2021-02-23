#include "EngineCore.h"

namespace Waffles{


    void EngineCore::load(){
        DEBUG("EngineCore Loading...");
        const char* appName = "Waffles-RTX-PBR";
        _window = new Waffles::Window(720, 720.0 / (16.0 / 9.0), appName);
        _vkInstance.load();
       
    }

    


    void EngineCore::update(){

    }

    void EngineCore::render(){


    }

    void EngineCore::unload(){
        UNLOAD_LOG("Unloading EngineCore...");
        _vkInstance.unload();

        _window->destroy();
        delete(_window);
        glfwTerminate();

    }



}
#include "EngineCore.h"

namespace Waffles{


    void EngineCore::load(){
        INIT_LOG("EngineCore Loading...");
        const char* appName = "Waffles-RTX-PBR";
        _window = new Waffles::Window(720, 720.0 / (16.0 / 9.0), appName);
        GLFWCallbacks::initCallBacks(_window);
        _vkInstance.load(_window->getWindow());
        _rasterizedCore.load();
       
    }

    


    void EngineCore::update(){
        if(InputManager::isKeyPressed(KeyCodes::KEY_ESCAPE)) glfwSetWindowShouldClose(_window->getWindow(), true);
        _rasterizedCore.update();
        InputManager::clear();
        glfwPollEvents();
    }

    void EngineCore::render(){
        _rasterizedCore.render();


    }

    void EngineCore::unload(){
        UNLOAD_LOG("Unloading EngineCore...");
        _vkInstance.unload();
        _rasterizedCore.unload();
        _window->destroy();
        delete(_window);
        glfwTerminate();

    }



}
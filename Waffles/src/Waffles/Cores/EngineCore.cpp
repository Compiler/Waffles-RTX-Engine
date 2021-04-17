#include "EngineCore.h"

namespace Waffles{


    void EngineCore::load(){
        INIT_LOG("EngineCore Loading...");
        const char* appName = "Waffles-RTX-PBR";
        _window = new Waffles::Window(WINDOW_WIDTH, WINDOW_HEIGHT, appName);
        GLFWCallbacks::initCallBacks(_window);
        _rasterizedCore.load(_window);
       
        GeneralVertex<glm::vec2, glm::vec2, float> vertex_info(glm::vec2(1, 1), glm::vec2(2,2), 3);

        auto e1 = vertex_info.element;
        auto e2 = vertex_info.recurse.element;
        auto e3 = vertex_info.recurse.recurse.element;
        DEBUG("(%f, %f), (%f, %f), %f", e1.x, e1.y, e2.x, e2.y, e3);

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
        _rasterizedCore.unload();
        _window->destroy();
        delete(_window);
        glfwTerminate();

    }



}
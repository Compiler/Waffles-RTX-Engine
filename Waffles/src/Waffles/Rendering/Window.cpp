#include "Window.h"

namespace Waffles{
 
    Window::Window(): _width(WINDOW_WIDTH), _height(WINDOW_HEIGHT), _name("DEFAULT CONSTRUCT NAME"){
        init();

    }

    Window::Window(uint16_t width, uint16_t height, const char* name): _width(width), _height(height), _name(name){
        init();

    }

    void Window::init(){
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
        _window = glfwCreateWindow(_width, _height, _name, nullptr, nullptr);

    }


    void Window::destroy(){
        glfwDestroyWindow(_window);


    }




}
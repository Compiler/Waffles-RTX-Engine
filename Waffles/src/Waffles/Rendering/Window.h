#pragma once
#include <GLFW/glfw3.h>
#include <Waffles/Waffles.h>
#include <stdint.h>
namespace Waffles{

    class Window{

        private:
            uint16_t _width, _height; 
            const char* _name;
            GLFWwindow* _window;
        public:
            Window();
            Window(uint16_t width, uint16_t height, const char* name);
            void init();


            GLFWwindow* getWindow()const{return _window;}

            bool isRunning() const {return !glfwWindowShouldClose(_window);}

            void destroy();

    };

}
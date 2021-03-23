#pragma once
#include <Waffles/Rendering/Window.h>
#include <GLFW/glfw3.h>

#include <Waffles/Tools/Input/InputManager.h>
#include <Waffles/Tools/Logging.h>

class GLFWCallbacks {

public:
	GLFWCallbacks() = delete;
	GLFWCallbacks(const GLFWCallbacks&) = delete;

	static void mouseClickCallback(GLFWwindow* window, int button, int action, int mods);
	static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);
	static void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos);
	static void initCallBacks(Waffles::Window* _windowRef);
	static void framebufferResizeCallback(GLFWwindow* window, int width, int height);

};
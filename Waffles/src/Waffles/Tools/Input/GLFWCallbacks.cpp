#include "GLFWCallbacks.h"


void GLFWCallbacks::framebufferResizeCallback(GLFWwindow* window, int width, int height){
	LOG("Resized");
	Waffles::WINDOW_WIDTH = width;
	Waffles::WINDOW_HEIGHT = height;
	glfwSetWindowSize(window, Waffles::WINDOW_WIDTH, Waffles::WINDOW_HEIGHT);
}

void GLFWCallbacks::initCallBacks(Waffles::Window* _windowRef){
	INIT_LOG("GLFWCallbacks Loading...");
	glfwSetKeyCallback(_windowRef->getWindow(), GLFWCallbacks::keyCallback);
	glfwSetCursorPosCallback(_windowRef->getWindow(), GLFWCallbacks::cursorPositionCallback);
	glfwSetMouseButtonCallback(_windowRef->getWindow(), GLFWCallbacks::mouseClickCallback);
	glfwSetFramebufferSizeCallback(_windowRef->getWindow(), GLFWCallbacks::framebufferResizeCallback);
}
void GLFWCallbacks::mouseClickCallback(GLFWwindow* window, int button, int action, int mods) {
	static uint16_t mouseKey;
	mouseKey = Waffles::MouseKeys::MOUSE_BUTTON_1;
	if (button == mouseKey && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
		Waffles::InputManager::addMousePress(mouseKey);
	}
	if (button == mouseKey && action == GLFW_RELEASE) {
		Waffles::InputManager::addMouseRelease(mouseKey);
	}

	mouseKey = Waffles::MouseKeys::MOUSE_BUTTON_2;
	if (button == mouseKey && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
		Waffles::InputManager::addMousePress(mouseKey);
	}
	if (button == mouseKey && action == GLFW_RELEASE) {
		Waffles::InputManager::addMouseRelease(mouseKey);
	}

	mouseKey = Waffles::MouseKeys::MOUSE_BUTTON_3;
	if (button == mouseKey && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
		Waffles::InputManager::addMousePress(mouseKey);
	}
	if (button == mouseKey && action == GLFW_RELEASE) {
		Waffles::InputManager::addMouseRelease(mouseKey);
	}

	mouseKey = Waffles::MouseKeys::MOUSE_BUTTON_4;
	if (button == mouseKey && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
		Waffles::InputManager::addMousePress(mouseKey);
	}
	if (button == mouseKey && action == GLFW_RELEASE) {
		Waffles::InputManager::addMouseRelease(mouseKey);
	}

	mouseKey = Waffles::MouseKeys::MOUSE_BUTTON_5;
	if (button == mouseKey && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
		Waffles::InputManager::addMousePress(mouseKey);
	}
	if (button == mouseKey && action == GLFW_RELEASE) {
		Waffles::InputManager::addMouseRelease(mouseKey);
	}
	mouseKey = Waffles::MouseKeys::MOUSE_BUTTON_6;
	if (button == mouseKey && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
		Waffles::InputManager::addMousePress(mouseKey);
	}
	if (button == mouseKey && action == GLFW_RELEASE) {
		Waffles::InputManager::addMouseRelease(mouseKey);
	}

	mouseKey = Waffles::MouseKeys::MOUSE_BUTTON_7;
	if (button == mouseKey && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
		Waffles::InputManager::addMousePress(mouseKey);
	}
	if (button == mouseKey && action == GLFW_RELEASE) {
		Waffles::InputManager::addMouseRelease(mouseKey);
	}

	mouseKey = Waffles::MouseKeys::MOUSE_BUTTON_8;
	if (button == mouseKey && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
		Waffles::InputManager::addMousePress(mouseKey);
	}
	if (button == mouseKey && action == GLFW_RELEASE) {
		Waffles::InputManager::addMouseRelease(mouseKey);
	}

}


void GLFWCallbacks::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode) {
	static uint16_t keyCheck;
	keyCheck = Waffles::KeyCodes::KEY_SPACE; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_APOSTROPHE; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_COMMA; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_MINUS; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_PERIOD; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_SLASH; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_0; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_1; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_2; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_3; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_4; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_5; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_6; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_7; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_8; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_9; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_SEMICOLON; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_EQUAL; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_A; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_B; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_C; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_D; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_E; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_F; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_G; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_H; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_I; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_J; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_K; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_L; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_M; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_N; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_O; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_P; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_Q; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_R; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_S; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_T; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_U; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_V; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_W; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_X; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_Y; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_Z; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_LEFT_BRACKET; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_BACKSLASH; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_RIGHT_BRACKET; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_GRAVE_ACCENT; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_WORLD_1; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_WORLD_2; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_ESCAPE; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_ENTER; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_TAB; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_BACKSPACE; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_INSERT; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_DELETE; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_RIGHT; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_LEFT; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_DOWN; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_UP; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_PAGE_UP; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_PAGE_DOWN; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_HOME; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_END; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_CAPS_LOCK; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_SCROLL_LOCK; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_NUM_LOCK; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_PRINT_SCREEN; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_PAUSE; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_F1; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_F2; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_F3; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_F4; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_F5; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_F6; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_F7; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_F8; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_F9; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_F10; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_F11; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_F12; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_F13; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_F14; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_F15; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_F16; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_F17; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_F18; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_F19; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_F20; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_F21; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_F22; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_F23; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_F24; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_F25; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_KP_0; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_KP_1; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_KP_2; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_KP_3; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_KP_4; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_KP_5; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_KP_6; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_KP_7; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_KP_8; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_KP_9; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_KP_DECIMAL; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_KP_DIVIDE; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_KP_MULTIPLY; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_KP_SUBTRACT; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_KP_ADD; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_KP_ENTER; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_KP_EQUAL; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_LEFT_SHIFT; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_LEFT_CONTROL; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_LEFT_ALT; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_LEFT_SUPER; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_RIGHT_SHIFT; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_RIGHT_CONTROL; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_RIGHT_ALT; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_RIGHT_SUPER; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }
	keyCheck = Waffles::KeyCodes::KEY_MENU; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { Waffles::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { Waffles::InputManager::addKeyRelease(keyCheck); }


}

void GLFWCallbacks::cursorPositionCallback(GLFWwindow* window, double xpos, double ypos) {
	Waffles::InputManager::addMousePosition(xpos, ypos);
}
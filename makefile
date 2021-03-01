PATH_TO_MINGW64 = C:/MinGW-64/bin
CXX = $(PATH_TO_MINGW64)/g++
C++_VERSION = c++11
CXXFLAGS = -std=$(C++_VERSION) -m64 -Wall -w -g -static-libgcc -static-libstdc++

OUT_DIR = bin
LAUNCHER_NAME = WafflesRTX
SRC_DIR = src
ENTRY_POINT = src/main.cpp

#Libs
VULKAN_ROOT = C:/VulkanSDK/1.2.162.1/
VULKAN_INC = $(VULKAN_ROOT)Include/
VULKAN_LIB = $(VULKAN_ROOT)Lib/


GLFW_ROOT = extern/glfw-3.3.3.64/
GLFW_INC = $(GLFW_ROOT)include
GLFW_LIB = $(GLFW_ROOT)lib
GLFW_SRC = $(GLFW_ROOT)src

GLM_ROOT = extern/glm/

STBIMAGE_ROOT = extern/stbimage

INC= -I $(SRC_DIR) -I $(GLFW_INC) -I $(STBIMAGE_ROOT) -I $(GLM_ROOT) -I $(VULKAN_INC) 
LIBS = -L $(GLFW_LIB) -L $(VULKAN_LIB) 
LINKS = -lglfw3dll -lvulkan-1 -lpthread #-lVkLayer_utils

#========================OBJECTS========================#
STARTUP_OBJS = $(OUT_DIR)/Startup.o
RENDERING_OBJS = $(OUT_DIR)/Window.o $(OUT_DIR)/VulkanInstance.o
INPUT_OBJS = $(OUT_DIR)/InputManager.o $(OUT_DIR)/GLFWCallbacks.o
CORE_OBJS = $(OUT_DIR)/RenderCore.o $(OUT_DIR)/EngineCore.o
OBJS = $(CORE_OBJS) $(ENGINE_CORE_OBJS) $(RENDERING_OBJS) $(STARTUP_OBJS) $(INPUT_OBJS)


ALL_SETTINGS = $(CXX) $(CXXFLAGS) $(LIBS) $(INC) 


#defaults to debug mode
main: $(ENTRY_POINT) $(OBJS)
	$(ALL_SETTINGS) -DDEBUG_MODE -o $(OUT_DIR)/$(LAUNCHER_NAME) $^ $(LINKS)
	./$(OUT_DIR)/$(LAUNCHER_NAME).exe

run:
	./$(OUT_DIR)/$(LAUNCHER_NAME).exe
	
release: $(ENTRY_POINT) $(OBJS)
	$(ALL_SETTINGS) -O3 -DRELEASE_MODE -o $(OUT_DIR)/$(LAUNCHER_NAME) $^ $(LINKS)
	./$(OUT_DIR)/$(LAUNCHER_NAME).exe

$(CORE_OBJS): $(OUT_DIR)/%.o: src/Cores/%.cpp
	$(ALL_SETTINGS) -c $< -o $@  

$(RENDERING_OBJS): $(OUT_DIR)/%.o: src/Rendering/%.cpp
	$(ALL_SETTINGS) -c $< -o $@  

$(STARTUP_OBJS): $(OUT_DIR)/%.o: src/Startup/%.cpp
	$(ALL_SETTINGS) -c $< -o $@  

$(INPUT_OBJS): $(OUT_DIR)/%.o: src/Tools/Input/%.cpp
	$(ALL_SETTINGS) -c $< -o $@  

  

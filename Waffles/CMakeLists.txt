set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(
    Waffles SHARED

    src/Waffles/Waffles.h
    src/Waffles/Waffles.cpp

    src/Waffles/Cores/EngineCore.cpp
    src/Waffles/Cores/EngineCore.h
    src/Waffles/Cores/RenderCore.cpp
    src/Waffles/Cores/RenderCore.h

    src/Waffles/Rendering/VulkanInstance.cpp
    src/Waffles/Rendering/VulkanInstance.h
    src/Waffles/Rendering/Window.cpp
    src/Waffles/Rendering/Window.h

    src/Waffles/Startup/Startup.cpp
    src/Waffles/Startup/Startup.h

    src/Waffles/Tools/FileUtils/FileLoader.cpp
    src/Waffles/Tools/FileUtils/FileLoader.h

    src/Waffles/Tools/Input/GLFWCallbacks.cpp
    src/Waffles/Tools/Input/GLFWCallbacks.h
    src/Waffles/Tools/Input/InputKeyStore.h
    src/Waffles/Tools/Input/InputManager.cpp
    src/Waffles/Tools/Input/InputManager.h
    src/Waffles/Tools/Logging.h
    
    src/Waffles/Tools/DebugUtils/VkDebugUtils.h
    src/Waffles/Tools/DebugUtils/VkDebugUtils.cpp

)


add_custom_command(TARGET Waffles PRE_BUILD        
    COMMAND ${CMAKE_COMMAND} -E copy_if_different  
    "${VULKAN_ROOT}/Lib/vulkan-1.lib"      
    "${EXECUTABLE_OUTPUT_PATH}")                 

add_custom_command(TARGET Waffles PRE_BUILD        
    COMMAND ${CMAKE_COMMAND} -E copy_if_different  
    "${GLFW_ABS_LIB}/glfw3dll.lib"      
    "${EXECUTABLE_OUTPUT_PATH}")  

add_custom_command(TARGET Waffles PRE_BUILD        
    COMMAND ${CMAKE_COMMAND} -E copy_if_different  
    "${GLFW_ABS_LIB}/glfw3.dll"      
    "${EXECUTABLE_OUTPUT_PATH}")  


target_compile_definitions(Waffles PUBLIC WAFFLE_DEBUG_MODE=1)

target_include_directories(Waffles PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
target_include_directories(Waffles PUBLIC "${ENTT_ABS_ROOT}")
target_include_directories(Waffles PUBLIC "${GLFW_ABS_INCLUDE}")
target_include_directories(Waffles PUBLIC "${EXTERN_DIR}/glm")
target_include_directories(Waffles PUBLIC "${EXTERN_DIR}/stbimage")
target_include_directories(Waffles PUBLIC "${VULKAN_INCLUDE}")


target_link_directories(Waffles PUBLIC "${GLFW_ABS_LIB}")
target_link_directories(Waffles PUBLIC "${VULKAN_LIB}")
target_link_libraries(Waffles glfw3dll)
target_link_libraries(Waffles vulkan-1)
target_link_libraries(Waffles pthread)

#find_package(glfw3 3.3 REQUIRED)
#target_link_libraries(Waffles glfw3)

find_package(OpenGL REQUIRED)
target_link_libraries(Waffles OpenGL::GL)



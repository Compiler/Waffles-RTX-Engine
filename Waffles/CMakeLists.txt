


add_library(
    Waffles SHARED

    src/Waffles/Waffles.h

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


)

target_compile_definitions(Waffles PUBLIC WAFFLE_DEBUG_MODE=1)

target_include_directories(Waffles PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
target_include_directories(Waffles PUBLIC "../extern/glfw-3.3.3.64/include")
target_include_directories(Waffles PUBLIC "../extern/glm")
target_include_directories(Waffles PUBLIC "../extern/stbimage")
target_include_directories(Waffles PUBLIC "${VULKAN_ROOT}/Include")


target_link_directories(Waffles PUBLIC "../extern/glfw-3.3.3.64/lib/")
target_link_directories(Waffles PUBLIC "${VULKAN_ROOT}/lib/")
target_link_libraries(Waffles glfw3dll)
target_link_libraries(Waffles vulkan-1)
target_link_libraries(Waffles pthread)

#find_package(glfw3 3.3 REQUIRED)
#target_link_libraries(Waffles glfw3)

find_package(OpenGL REQUIRED)
target_link_libraries(Waffles OpenGL::GL)

#add_compile_options(-lglfw3dll)
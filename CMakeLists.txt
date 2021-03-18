cmake_minimum_required(VERSION 3.17.3)
project (WafflesMain VERSION 1.0.0)

set(VULKAN_ROOT C:/VulkanSDK/1.2.162.1)
set(VULKAN_LIB "${VULKAN_ROOT}/Lib/")
set(VULKAN_INCLUDE "${VULKAN_ROOT}/Include")


set(GLFW_ROOT extern/glfw-3.3.3.64)
set(GLFW_ABS_ROOT "${CMAKE_SOURCE_DIR}/${GLFW_ROOT}")
set(GLFW_ABS_LIB "${GLFW_ABS_ROOT}/lib")
set(GLFW_ABS_INCLUDE "${GLFW_ABS_ROOT}/include")

set(ENTT_ROOT extern/entt)
set(ENTT_ABS_ROOT "${CMAKE_SOURCE_DIR}/${ENTT_ROOT}")


set(EXTERN_DIR "${CMAKE_SOURCE_DIR}/extern")

#cmake -G "MinGW Makefiles" ..
#target_include_directories(src PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}src/")
set(LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}")
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}")

message("${GLFW_ABS_INCLUDE}")

add_subdirectory(Waffles) #this needs to be first
add_subdirectory(Driver)






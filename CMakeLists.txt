cmake_minimum_required(VERSION 3.17.3)
project (WafflesMain VERSION 1.0.0)

set(VULKAN_ROOT C:/VulkanSDK/1.2.162.1)


#cmake -G "MinGW Makefiles" ..
#target_include_directories(src PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}src/")
set(LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}")
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}")
add_subdirectory(Waffles) #this needs to be first
add_subdirectory(Driver)



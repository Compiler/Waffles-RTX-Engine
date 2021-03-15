set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(WafflesDriver src/main.cpp)
target_link_libraries(WafflesDriver PRIVATE Waffles)

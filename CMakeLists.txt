cmake_minimum_required(VERSION 3.0)
project(RayTracer)
set(CMAKE_CXX_STANDARD 14)

include(FetchContent)

FetchContent_Declare(
 glm
 GIT_REPOSITORY https://github.com/g-truc/glm
 GIT_TAG        0.9.9.8
)
FetchContent_MakeAvailable(glm)

include_directories(${glm_SOURCE_DIR})

add_executable(RayTracer main.cpp sphere.cpp camera.cpp)
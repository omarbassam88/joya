cmake_minimum_required(VERSION 3.16)
project(JOYA VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(thirdparty/glfw)

add_subdirectory(thirdparty/glad)

add_subdirectory(thirdparty/spdlog)

add_subdirectory(thirdparty/imgui)

add_subdirectory(thirdparty/glm)

add_subdirectory(joya)

add_subdirectory(test_app)



cmake_minimum_required(VERSION 3.16)
project(JOYA VERSION 0.1.0)

include(CTest)
enable_testing()

add_subdirectory(thirdparty/glfw)

add_subdirectory(joya)

include_directories(joya/src)
include_directories(joya)


add_subdirectory(test_app)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)


add_library(joya 
    App.cpp
    Log.cpp
    window.cpp
)

target_include_directories(joya INTERFACE ${JOYA_SOURCE_DIR}/joya/include)
target_include_directories(joya PUBLIC ${JOYA_SOURCE_DIR}/joya/src)

target_link_libraries(joya 
    GL
    glfw 
    spdlog
    glad
    imgui
)

add_library(joya 
    App.cpp
    Log.cpp
    window.cpp
    Layer.cpp
    LayerStack.cpp
    ImGuiBuild.cpp
    UILayer.cpp
    Input.cpp 
    Render/OpenGLContext.cpp 
    Render/Shader.cpp 
)

target_include_directories(joya INTERFACE ${JOYA_SOURCE_DIR}/joya/include)
target_include_directories(joya PUBLIC ${JOYA_SOURCE_DIR}/joya/src)

target_link_libraries(joya 
    glfw 
    spdlog
    glad
    imgui
    glm
)
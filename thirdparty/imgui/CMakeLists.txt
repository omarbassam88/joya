

add_library(imgui
    imgui/imgui.cpp
    imgui/imgui_demo.cpp
    imgui/imgui_draw.cpp
    imgui/imgui_widgets.cpp
)

target_include_directories(imgui PUBLIC ${JOYA_SOURCE_DIR}/thirdparty/imgui/imgui)

include_directories(./imgui)
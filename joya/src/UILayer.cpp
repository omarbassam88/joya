#include "UILayer.h"
#include "App.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <imgui.h>
#include <examples/imgui_impl_glfw.h>
#include <examples/imgui_impl_opengl3.h>

namespace JY
{
    UILayer::UILayer()
        : Layer("UILayer")
    {
    }

    void UILayer::OnAttach()
    {
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO &io = ImGui::GetIO();
        (void)io;

        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
        //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;   // Enable Docking
        io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable; // Enable Multi-Viewport / Platform Windows
        //io.ConfigFlags |= ImGuiConfigFlags_ViewportsNoTaskBarIcons;
        //io.ConfigFlags |= ImGuiConfigFlags_ViewportsNoMerge;

        ImGui::StyleColorsDark;

        GLFWwindow *window = static_cast<GLFWwindow *>(App::s_Instance->GetWindow().GetWindow());
        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init("#version 410");
    }

    void UILayer::OnDetach()
    {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
    }

    void UILayer::OnUpdate()
    {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        bool show_demo_window = true;

        if (show_demo_window)
            ImGui::ShowDemoWindow(&show_demo_window);

        // Rendering
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        ImGuiIO &io = ImGui::GetIO();
        (void)io;

        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            GLFWwindow *backup_current_context = glfwGetCurrentContext();
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
            glfwMakeContextCurrent(backup_current_context);
        }
    }

    void UILayer::OnEvent(Event &e)
    {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<MouseButtonPressed>(std::bind(&UILayer::OnMouseButtonPressed, this, std::placeholders::_1));
        dispatcher.Dispatch<MouseButtonReleased>(std::bind(&UILayer::OnMouseButtonReleased, this, std::placeholders::_1));
    }

    bool UILayer::OnMouseButtonPressed(MouseButtonPressed &e)
    {
        ImGuiIO &io = ImGui::GetIO();
        io.MouseDown[e.GetButton()] = true;
        JY_INFO("IMGUI Mouse BUTTON {} PRESSED", e.GetButton());
        return false;
    }

    bool UILayer::OnMouseButtonReleased(MouseButtonReleased &e)
    {
        ImGuiIO &io = ImGui::GetIO();
        io.MouseDown[e.GetButton()] = false;
        JY_INFO("IMGUI Mouse BUTTON {} RELEASED", e.GetButton());
        return false;
    }

} // namespace JY

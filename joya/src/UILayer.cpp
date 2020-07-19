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
        // ImGuiIO &io = ImGui::GetIO();
        // (void)io;

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
        GLFWwindow *window = static_cast<GLFWwindow *>(App::s_Instance->GetWindow().GetWindow());
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        bool show_demo_window = true;
        bool show_another_window = false;
        ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

        if (show_demo_window)
            ImGui::ShowDemoWindow(&show_demo_window);

        // Rendering
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
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
        JY_INFO("IMGUI Mouse BUTTON {} PRESSED",e.GetButton());
        return false;
    }

    bool UILayer::OnMouseButtonReleased(MouseButtonReleased &e)
    {
        ImGuiIO &io = ImGui::GetIO();
        io.MouseDown[e.GetButton()] = false;
        JY_INFO("IMGUI Mouse BUTTON {} RELEASED",e.GetButton());
        return false;
    }

} // namespace JY

#include "Input.h"

namespace JY
{

    // *Input Input::s_instance = new Input();

    bool Input::IsKeyPressed(int key)
    {
        auto window = static_cast<GLFWwindow *>(App::s_Instance->GetWindow().GetWindow());
        auto state = glfwGetKey(window, key);
        return state == GLFW_PRESS;
    }

    bool Input::IsMouseButtonPressed(int key)
    {
        auto window = static_cast<GLFWwindow *>(App::s_Instance->GetWindow().GetWindow());
        auto state = glfwGetMouseButton(window, key);
        JY_CRITICAL("A MOUSE BUTTON IS PRESSED");
        return state == GLFW_PRESS;
    }

    std::pair<float, float> Input::GetMousePosition()
    {
        auto window = static_cast<GLFWwindow *>(App::s_Instance->GetWindow().GetWindow());
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        return {(float)xpos, (float)ypos};
    }

    float Input::GetMouseX()
    {
        auto [x, y] = GetMousePosition();
        return x;
    }

    float Input::GetMouseY()
    {
        auto [x, y] = GetMousePosition();
        return y;
    }
} // namespace JY
#include "App.h"

namespace JY
{

    App *App::s_Instance = nullptr;

    App::App()
    {
        s_Instance = this;
        console->Init();
        m_win = std::make_unique<Window>(1280, 720, "Hello JOYA APP");
        m_win->Start();
        m_win->SetEventCallback(std::bind(&App::OnEvent, this, std::placeholders::_1));
        m_Running = true;
        m_UILayer = new UILayer();
        JY_INFO("{}", m_UILayer->GetName());
        PushOverlay(m_UILayer);

        JY_INFO("App is Initialised successfully");

        const char *vertexShaderSource = R"(
            #version 330 core
            layout(location = 0) in vec3 aPos;
            void main()
            {
                gl_Position = vec4(aPos, 1.0);
            }
            )";

        const char *fragmentShaderSource = R"(
            #version 330 core
            out vec4 FragColor;
            uniform vec4 ourColor;
            void main()
            {
                FragColor = ourColor;
            })";

        m_shader = new Shader(vertexShaderSource, fragmentShaderSource);

        float vertices[] = {
            0.5f, -0.5f, 0.0f,  // bottom right
            -0.5f, -0.5f, 0.0f, // bottom left
            0.0f, 0.5f, 0.0f    // top
        };

        unsigned int VBO, VAO;
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
        glEnableVertexAttribArray(0);
        glBindVertexArray(VAO);
        m_shader->Bind();
    }

    App::~App()
    {
    }

    void App::Run()
    {
        while (m_Running)
        {
            m_win->Clear();
            m_UILayer->OnUpdate();

            // update shader uniform
            float timeValue = glfwGetTime();
            float greenValue = sin(timeValue) / 2.0f + 0.5f;
            int vertexColorLocation = glGetUniformLocation(m_shader->GetRenderID(), "ourColor");
            glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);

            // render the triangle
            glDrawArrays(GL_TRIANGLES, 0, 3);

            if (Input::IsKeyPressed(JY_KEY_ESCAPE))
            {
                Quit();
            }

            m_win->Update();
        }
        m_win->Destroy();
    }

    void App::OnEvent(Event &e)
    {

        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowResizeEvent>(std::bind(&App::OnWindowResize, this, std::placeholders::_1));
        dispatcher.Dispatch<WindowCloseEvent>(std::bind(&App::OnWindowClose, this, std::placeholders::_1));

        for (auto it = m_LayerStack.begin(); it != m_LayerStack.end(); it++)
        {
            (*it)->OnEvent(e);
        }
    }

    void App::PushLayer(Layer *layer)
    {
        m_LayerStack.PushLayer(layer);
        layer->OnAttach();
    }

    void App::PushOverlay(Layer *layer)
    {
        m_LayerStack.PushOverlay(layer);
        layer->OnAttach();
    }

    bool App::Quit()
    {
        m_Running = false;
        return true;
    }

    bool App::OnWindowResize(WindowResizeEvent &e)
    {

        JY_WARN("Width: {}, Hieght: {}", e.GetWidth(), e.GetHeight());
        return true;
    }

    bool App::OnWindowClose(WindowCloseEvent &e)
    {
        Quit();
        return true;
    }

} // namespace JY
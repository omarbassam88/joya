#ifndef __SHADER_H__
#define __SHADER_H__

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>

namespace JY
{
    class Shader
    {
    private:
        /* data */
        int m_RenderID;

    public:
        Shader(const std::string &vertexSrc, const std::string &fragmentSrc);
        ~Shader();

        int GetRenderID() { return m_RenderID; }

        void Bind();
        void UnBind();
    };

} // namespace JY

#endif // __SHADER_H__
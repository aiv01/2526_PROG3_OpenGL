#pragma once
#include <glad/gl.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

class Ex08PhongDraw 
{
public:
    Ex08PhongDraw();
    ~Ex08PhongDraw();
    void Update(float InDeltaTime);
private:
    class OGLProgram* Program;
    GLuint Vao;
    GLuint Vbo;
    class OGLTexture* TrupTexture;
    size_t TrupVertexCount;
    glm::mat4 View;
    glm::mat4 Projection;
};

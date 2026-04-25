#pragma once
#include <glad/gl.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include "OGLProgram.h"

class Ex08PhongDrawAB 
{
public:
    Ex08PhongDrawAB();
    ~Ex08PhongDrawAB();
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

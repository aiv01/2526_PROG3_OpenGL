#pragma once
#include <glad/gl.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include "OGLProgram.h"

class Ex08PhongDrawA 
{

    OGLProgram* LightProgram = nullptr;
    GLuint LightVao = 0;
    GLuint LightVbo = 0;
    int LightVertexCount = 36;
    glm::vec3 CameraPos;

public:
    Ex08PhongDrawA();
    ~Ex08PhongDrawA();
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

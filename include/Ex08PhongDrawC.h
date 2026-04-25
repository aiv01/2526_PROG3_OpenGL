#pragma once
#include <glad/gl.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include "OGLProgram.h"

class Ex08PhongDrawC 
{

    OGLProgram* LightProgram = nullptr;
    GLuint LightVao = 0;
    GLuint LightVbo = 0;
    int LightVertexCount = 36;
    glm::vec3 CameraPos;

public:
    Ex08PhongDrawC();
    ~Ex08PhongDrawC();
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

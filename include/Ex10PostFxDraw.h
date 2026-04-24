#pragma once
#include <glad/gl.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

class Ex10PostFxDraw 
{
public:
    Ex10PostFxDraw();
    ~Ex10PostFxDraw();
    void Update(float InDeltaTime);
private:
    class OGLProgram* Program;
    GLuint Vao;
    GLuint Vbo;
    class OGLTexture* BoxTexture;
    glm::mat4 View;
    glm::mat4 Projection;

    GLuint SceneFbo;
    GLuint SceneTexture;
    GLuint SceneRbo;
};

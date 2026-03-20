#pragma once
#include <glad/gl.h>

class Ex02QuadDraw 
{
public:
    Ex02QuadDraw();
    ~Ex02QuadDraw();
    void Update(float InDeltaTime);
private:
    GLuint ProgramId;
    GLuint Vao;
    GLuint Vbo;
};

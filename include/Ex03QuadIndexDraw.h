#pragma once
#include <glad/gl.h>

class Ex03QuadIndexDraw 
{
public:
    Ex03QuadIndexDraw();
    ~Ex03QuadIndexDraw();
    void Update(float InDeltaTime);
private:
    GLuint ProgramId;
    GLuint Vao;
    GLuint Vbo;
    GLuint Ebo;
};

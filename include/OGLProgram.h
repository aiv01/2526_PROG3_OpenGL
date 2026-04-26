#pragma once
#include <string>
#include <glad/gl.h>

class OGLProgram
{
public:
    OGLProgram(const std::string& InVertexPath, const std::string& InFragmPath);
    ~OGLProgram();
    void Bind();
    void SetUniform(const std::string &Name, float Value);

public:
    GLuint ProgramId;
};
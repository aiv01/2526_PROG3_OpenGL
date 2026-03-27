#pragma once
#include <string>
#include <glad/gl.h>

class OGLTexture 
{
public:
    OGLTexture(const std::string& InImagePath);
    ~OGLTexture();
    void Bind(GLuint TextureSlotId);
private:
    GLuint TextureId;
};
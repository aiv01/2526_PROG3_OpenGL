#pragma once
#include <string>
#include <glad/gl.h>
#include <vector>
#include <ctime>
class OGLTexture 
{
public:
    OGLTexture(const std::string& InImagePath);
    OGLTexture(int Width, int Height);
    void UpdateRandomPixels();
    ~OGLTexture();
    void Bind(GLuint TextureSlotId);
private:
    GLuint TextureId;
    int Width, Height;
};



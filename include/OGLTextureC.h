#pragma once
#include <string>
#include <glad/gl.h>
#include <vector>
#include <ctime>
class OGLTextureC
{
public:
    OGLTextureC(const std::string& InImagePath);
    OGLTextureC(int Width, int Height);
    void UpdateRandomPixels();
    ~OGLTextureC();
    void Bind(GLuint TextureSlotId);
private:
    GLuint TextureId;
    int Width, Height;
};



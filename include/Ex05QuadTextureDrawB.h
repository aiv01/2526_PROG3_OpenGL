#pragma once
#include <glad/gl.h>

class Ex05QuadTextureDrawB 
{
public:
    Ex05QuadTextureDrawB();
    ~Ex05QuadTextureDrawB();
    void Update(float InDeltaTime);
private:
    class OGLProgram* Program;
    GLuint Vao;
    GLuint Vbo;
    GLuint Ebo;
    //GLuint SmileTextureId;
    //GLuint BoxTextureId;
    class OGLTexture* SmileTexture;
    class OGLTexture* BoxTexture;
    class OGLTexture* TVNoiseTexure;
    float mix_factor;
};

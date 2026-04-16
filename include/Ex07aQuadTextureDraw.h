#pragma once
#include <glad/gl.h>

class Ex07aQuadTextureDraw 
{
public:
    Ex07aQuadTextureDraw();
    ~Ex07aQuadTextureDraw();
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

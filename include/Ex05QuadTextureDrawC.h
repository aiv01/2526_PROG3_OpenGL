#pragma once
#include <glad/gl.h>

class Ex05QuadTextureDrawC 
{
public:
    Ex05QuadTextureDrawC();
    ~Ex05QuadTextureDrawC();
    void Update(float InDeltaTime);
private:
    class OGLProgram* Program;
    GLuint Vao;
    GLuint Vbo;
    GLuint Ebo;
    //GLuint SmileTextureId;
    //GLuint BoxTextureId;
    class OGLTextureC* SmileTexture;
    class OGLTextureC* BoxTexture;
    class OGLTextureC* TVNoiseTexure;
    float mix_factor;
};

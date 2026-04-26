#include "Ex05QuadTextureDrawC.h"
#include <vector>
#include "OGLProgram.h"
#include <cmath>
#include "OGLTextureC.h"

struct XColor {
    float R;
    float G;
    float B;
    float A;
};


Ex05QuadTextureDrawC::Ex05QuadTextureDrawC()
{
    mix_factor=0.5f;
    Program = new OGLProgram("resources/shaders/quadtexture.vert", "resources/shaders/quadtextureC.frag");

    std::vector<float> Vertices = {
        // Positions         // Uvs
        -0.5f, -0.5f, 0.f,   0.f, 0.f,   // bottom-left
         0.5f, -0.5f, 0.f,   1.f, 0.f,   // bottom-right
         0.5f,  0.5f, 0.f,   1.f, 1.f,   // top-right
        -0.5f,  0.5f, 0.f,   0.f, 1.f,   // top-left 
    };

    std::vector<uint32_t> Indexes = {
        0, 1, 2, // Triangle Right
        0, 2, 3  // Triangle Left
    };

    //1. Create VAO
    glGenVertexArrays(1, &Vao);
    glBindVertexArray(Vao);

    //2. Create VBO to load data
    glGenBuffers(1, &Vbo);
    glBindBuffer(GL_ARRAY_BUFFER, Vbo);

    size_t DataSize = Vertices.size() * sizeof(float);
    glBufferData(GL_ARRAY_BUFFER, DataSize, Vertices.data(), GL_STATIC_DRAW);

    //3. Link to Vertex Shader
    GLuint Location_0 = 0;
    glVertexAttribPointer(Location_0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(Location_0);

    GLuint Location_1 = 1;
    glVertexAttribPointer(Location_1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(Location_1);

    //4. Create EBO
    glGenBuffers(1, &Ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, Indexes.size() * sizeof(uint32_t), Indexes.data(), GL_STATIC_DRAW);

    //5. Set Viewport
    glViewport(0, 0, 800, 600);
    glClearColor(0.5f, 0.5f, 0.5f, 1.f);
    
    Program->Bind();

    //Exercise2 tv noice effect
    //TVNoiseTexure = new OGLTextureC(128, 128); //not used anymore

    Program->SetUniform("time", 0);

    //TVNoiseTexure->Bind(GL_TEXTURE1);//not used anymore

    //7. Enable Alpha Blending
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

Ex05QuadTextureDrawC::~Ex05QuadTextureDrawC()
{
    glDeleteVertexArrays(1, &Vao);
    glDeleteBuffers(1, &Vbo);
    glDeleteBuffers(1, &Ebo);
  
    delete Program;
}

void Ex05QuadTextureDrawC::Update(float InDeltaTime)
{
    //Ex2
    //TVNoiseTexure->UpdateRandomPixels();

    static float ElapsedTime = 0.0f;
    ElapsedTime += InDeltaTime;

    glClear(GL_COLOR_BUFFER_BIT);
    Program->Bind();
    Program->SetUniform("time", ElapsedTime);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)0);
}

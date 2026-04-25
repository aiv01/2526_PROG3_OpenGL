#include "OGLTextureC.h"
#include "stb_image.h"
#include <iostream>

static GLuint CreateTexture(const std::string& InImagePath);

OGLTextureC::OGLTextureC(const std::string& InImagePath)
{
    TextureId = CreateTexture(InImagePath);
}

OGLTextureC::~OGLTextureC()
{
    glDeleteTextures(1, &TextureId);
}

void OGLTextureC::Bind(GLuint TextureSlotId)
{
    glActiveTexture(TextureSlotId);
    glBindTexture(GL_TEXTURE_2D, TextureId);
}

GLuint CreateTexture(const std::string& InImagePath)
{
    stbi_set_flip_vertically_on_load(true);

    int Width, Height, Channels;
    uint8_t* Data = stbi_load(InImagePath.c_str(), &Width, &Height, &Channels, 0);
    if (Data == NULL)
    {
        std::cout << "Error reading image: " << InImagePath;
        throw std::runtime_error("Error reading image");
    }

    GLenum Format = Channels == 3 ? GL_RGB : GL_RGBA;

    GLuint TextureId;
    glGenTextures(1, &TextureId);
    glBindTexture(GL_TEXTURE_2D, TextureId);

    // Upload data to GPU
    glTexImage2D(GL_TEXTURE_2D, 0, Format, Width, Height, 0, Format, GL_UNSIGNED_BYTE, Data);

    // Wrapping
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    // Filtering
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

    // MipMapping (Optional)
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(Data);
    return TextureId;
}


//Ex2 tv noice constructor
OGLTextureC::OGLTextureC(int InWidth, int InHeight)
    : Width(InWidth), Height(InHeight) 
{


    glGenTextures(1, &TextureId);
    glBindTexture(GL_TEXTURE_2D, TextureId);
    // Upload data to GPU
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Width, Height, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);

    // Wrapping
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    // Filtering
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    
    UpdateRandomPixels();
}

//Ex2 tv noice update
void OGLTextureC::UpdateRandomPixels()
{
    // Generiamo nuovi pixel bianco/nero (TV Noise)
    std::vector<uint8_t> NoiseData(Width * Height * 3);
    for (int i = 0; i < Width * Height; i++) {
        uint8_t value = std::rand() % 256; //scale of grey:
        NoiseData[i * 3 + 0] = value;
        NoiseData[i * 3 + 1] = value;
        NoiseData[i * 3 + 2] = value;
    }


    // Upload data to GPU
    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, Width, Height, GL_RGB, GL_UNSIGNED_BYTE, NoiseData.data());
}
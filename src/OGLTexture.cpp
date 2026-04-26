#include "OGLTexture.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <iostream>

static GLuint CreateTexture(const std::string& InImagePath);

OGLTexture::OGLTexture(const std::string& InImagePath)
{
    TextureId = CreateTexture(InImagePath);
}

OGLTexture::~OGLTexture()
{
    glDeleteTextures(1, &TextureId);
}

void OGLTexture::Bind(GLuint TextureSlotId)
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


//ex 1 constructor
OGLTexture::OGLTexture(int Width, int Height)
{
    // Generate here random pixel to laod on gpu
    std::vector<uint8_t> RandomPixels;
    RandomPixels.resize(Width * Height * 3); // caus is RGB

    for (int i = 0; i < RandomPixels.size(); i++) 
    {
        RandomPixels[i] = std::rand() % 256; // from 0 e 255 - color
    }

    glGenTextures(1, &TextureId);
    glBindTexture(GL_TEXTURE_2D, TextureId);

    // Upload data to GPU
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Width, Height, 0, GL_RGB, GL_UNSIGNED_BYTE, RandomPixels.data());

    // Wrapping
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // Filtering
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);


}

/*
//Ex2 tv noice constructor
OGLTexture::OGLTexture(int InWidth, int InHeight)
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
*/
//Ex2 tv noice update
void OGLTexture::UpdateRandomPixels()
{
    // Generiamo nuovi pixel bianco/nero (TV Noise)
    std::vector<uint8_t> NoiseData(Width * Height * 3);
    for (int i = 0; i < NoiseData.size(); i++) {
        NoiseData[i] = std::rand() % 256;
    }


    // Upload data to GPU
    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, Width, Height, GL_RGB, GL_UNSIGNED_BYTE, NoiseData.data());
}
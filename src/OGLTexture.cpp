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

//
// Created by Prasanga Tiwari on 5/11/24.
//
#include "pch.h"
#include "glad/glad.h"
#include "stb_image.h"
#include "utility.h"
#include "ImageOpenGL.h"


//
// Created by Prasanga Tiwari on 5/11/24.
//
#include "pch.h"
#include "glad/glad.h"
#include "stb_image.h"
#include "utility.h"
#include "ImageOpenGL.h"
namespace Ultimate{
    ImageOpenGL::ImageOpenGL(const std::string& filePath) {
        std::cout << "Attempting to load texture from: " << filePath << std::endl;

        glGenTextures(1, &mTexture);
        glBindTexture(GL_TEXTURE_2D, mTexture);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        int nrChannels;
        stbi_set_flip_vertically_on_load(true);
        unsigned char* data = stbi_load(filePath.c_str(), &mWidth, &mHeight, &nrChannels, 0);

        GLenum format = (nrChannels == 4) ? GL_RGBA : GL_RGB;

        if (data) {
            std::cout << "Successfully loaded texture: " << filePath << std::endl;
            glTexImage2D(GL_TEXTURE_2D, 0, format, mWidth, mHeight, 0, format, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        } else {
            std::cerr << "Failed to load texture: " << filePath << std::endl;
        }
        stbi_image_free(data);
    }

    ImageOpenGL::ImageOpenGL(std::string &&filePath) {
        std::cout << "Attempting to load texture from: " << filePath << std::endl;

        glGenTextures(1, &mTexture);
        glBindTexture(GL_TEXTURE_2D, mTexture);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        int nrChannels;
        stbi_set_flip_vertically_on_load(true);
        unsigned char* data = stbi_load(filePath.c_str(), &mWidth, &mHeight, &nrChannels, 0);

        GLenum format = (nrChannels == 4) ? GL_RGBA : GL_RGB;

        if (data) {
            std::cout << "Successfully loaded texture: " << filePath << std::endl;
            glTexImage2D(GL_TEXTURE_2D, 0, format, mWidth, mHeight, 0, format, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        } else {
            std::cerr << "Failed to load texture: " << filePath << std::endl;
        }
        stbi_image_free(data);
    }

    int ImageOpenGL::GetWidth() const {
        return mWidth;
    }

    int ImageOpenGL::GetHeight() const{
        return mHeight;
    }

    void ImageOpenGL::Bind() const {
        glBindTexture(GL_TEXTURE_2D, mTexture);
    }

    ImageOpenGL::~ImageOpenGL(){
        glDeleteTextures(1, &mTexture);
    }


}
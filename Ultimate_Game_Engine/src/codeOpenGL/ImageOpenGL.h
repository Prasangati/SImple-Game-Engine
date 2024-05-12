//
// Created by Prasanga Tiwari on 5/11/24.
//

#ifndef YOURPROJECTNAME_IMAGEOPENGL_H
#define YOURPROJECTNAME_IMAGEOPENGL_H
#include "../pch.h"
#include "../ImageImplement.h"

namespace Ultimate{
    class ImageOpenGL: public ImageImplement{
    public:
            ImageOpenGL(const std::string& filePath);
            ImageOpenGL(std::string&& filePath);


            virtual int GetWidth() const override;
            virtual int GetHeight() const override;
            virtual void Bind() const override;
            ~ImageOpenGL();
    private:
        unsigned int mTexture{0};
        int mWidth{0};
        int mHeight{0};
    };
}

#endif //YOURPROJECTNAME_IMAGEOPENGL_H

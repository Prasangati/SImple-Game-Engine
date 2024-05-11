//
// Created by Prasanga Tiwari on 5/11/24.
//

#ifndef YOURPROJECTNAME_IMAGE_H
#define YOURPROJECTNAME_IMAGE_H

#include "pch.h"
#include "utility.h"
#include "ImageImplement.h"

namespace Ultimate {
    class Image {
    public:
        Image(const std::string& filepath);
        Image(std::string&& filepath);

        int GetWidth() const;
        int GetHeight() const;

        void Bind();
    private:
        std::unique_ptr<ImageImplement>  mImplementation;
    };
}

#endif //YOURPROJECTNAME_IMAGE_H

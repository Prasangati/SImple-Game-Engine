//
// Created by Prasanga Tiwari on 5/11/24.
//
#include "pch.h"
#include "Image.h"
namespace Ultimate{
    Image::Image(const std::string &filepath) {
#ifdef ULTIMATE_OPENGL
        mImplementation = std::unique_ptr{ new ImageOpenGl{filePath}};
#else
        #error "only openGl is supoorted so far"
#endif
    }

    Image::Image(std::string &&filepath) {
#ifdef ULTIMATE_OPENGL
        mImplementation = std::unique_ptr{ new ImageOpenGl{std::move(filePath)}};
#else
#error "only openGl is supoorted so far"
#endif
    }

    int Image::GetWidth() const {
        return mImplementation->GetWidth();
    }

    int Image::GetHeight() const {
        return mImplementation->GetHeight();
    }

    void Image::Bind() {
        mImplementation->Bind();
    }


}
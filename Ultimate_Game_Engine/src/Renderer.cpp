//
// Created by Prasanga Tiwari on 5/13/24.
//
#include "pch.h"
#include "Renderer.h"
#include "codeOpenGL/RendererOpenGL.h"
namespace Ultimate{

    void Renderer::Draw(Image &pic, int x, int y) {
        mInstance->mImplementation->Draw(pic,x,y);
    }

    void Renderer::Init() {
        if (!mInstance){
            mInstance = new Renderer;
        }
    }

    Renderer *Renderer::GetInstance() {
        return mInstance;
    }

    void Renderer::Draw(Image &pic, Shader &shader, int x, int y) {
        mInstance->mImplementation->Draw(pic, shader, x, y);
    }

    void Renderer::ClearScreen() {
        mInstance->mImplementation->ClearScreen();

    }

    Renderer::Renderer() {
#ifdef ULTIMATE_OPENGL
        mImplementation = std::unique_ptr<RendererImplement>{new RendererOpenGL};

#else
#error "only openGl is supoorted so far"
#endif
    }

}
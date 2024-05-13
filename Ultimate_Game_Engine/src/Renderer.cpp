//
// Created by Prasanga Tiwari on 5/13/24.
//
#include "pch.h"
#include "Renderer.h"
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

    Renderer::Renderer() {

    }
}
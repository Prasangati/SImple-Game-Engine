//
// Created by Prasanga Tiwari on 5/13/24.
//

#ifndef YOURPROJECTNAME_RENDERER_H
#define YOURPROJECTNAME_RENDERER_H
#include "pch.h"
#include "utility.h"
#include "Image.h"
namespace Ultimate {
    class Renderer {
    public:
        static void Init();
        static Renderer* GetInstance();

        static void Draw(Image& pic, int x, int y);
    private:
        std::unique_ptr<RendererImplement> mImplementation;
        Renderer();
        inline static Renderer* mInstance{nullptr};
    };
}

#endif //YOURPROJECTNAME_RENDERER_H

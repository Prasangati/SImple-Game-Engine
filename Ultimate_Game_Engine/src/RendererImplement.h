//
// Created by Prasanga Tiwari on 5/13/24.
//

#ifndef YOURPROJECTNAME_RENDERERIMPLEMENT_H
#define YOURPROJECTNAME_RENDERERIMPLEMENT_H
#include "Image.h"
#include "Shader.h"
namespace Ultimate{
    class RendererImplement{
    public:
        virtual void Draw(Image& pic, int x, int y) = 0;
        virtual void Draw(Image& pic,Shader& shader ,int x, int y) = 0;
        virtual void ClearScreen() = 0;
        virtual ~RendererImplement(){};
    };
}


#endif //YOURPROJECTNAME_RENDERERIMPLEMENT_H

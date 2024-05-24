//
// Created by Prasanga Tiwari on 5/13/24.
//

#ifndef YOURPROJECTNAME_RENDEREROPENGL_H
#define YOURPROJECTNAME_RENDEREROPENGL_H

#include "RendererImplement.h"
#include "Shader.h"
namespace Ultimate{
    class RendererOpenGL : public RendererImplement {
    public :
        RendererOpenGL();
        ~RendererOpenGL();
        virtual void Draw(Image& pic, int x, int y) override;
        virtual void Draw(Image& pic, Shader& shader ,int x, int y) override;
        virtual void ClearScreen() override;


    private:
        std::unique_ptr<Shader> mShaderPtr;
    };
}

#endif //YOURPROJECTNAME_RENDEREROPENGL_H

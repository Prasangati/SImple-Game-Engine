//
// Created by tiwari on 5/12/2024.
//

#ifndef SHADEROPENGL_H
#define SHADEROPENGL_H
#include "pch.h"
#include"ShaderImplement.h"
namespace Ultimate{
    class ShaderOpenGL : public ShaderImplement{
    public:
        ShaderOpenGL(const std::string& vertexFile, const std::string& fragmentFile);
        ShaderOpenGL(std::string&& vertexFile, std::string&& fragmentFile);

        virtual void Bind() override;
    private:
        unsigned int mShaderprog{0};
        std::string ReadFile(const std::string& fileName);
        std::string ReadFile(std::string&& fileName);
    };
}

#endif //SHADEROPENGL_H


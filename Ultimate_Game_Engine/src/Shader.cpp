//
// Created by Prasanga Tiwari on 5/12/24.
//
#include "pch.h"
#include "Shader.h"
namespace Ultimate
{
    Shader::Shader(const std::string &vertexFile, const std::string &fragmentFile) {
#ifdef ULTIMATE_OPENGL
        mImplementation = std::unique_ptr<ShaderImplement>{new ShaderOpenGL{vertexFile,fragmentFile}};

#else
#error "only openGl is supoorted so far"
#endif
    }

    Shader::Shader(std::string&& vertexFile, std::string&& fragmentFile) {
#ifdef ULTIMATE_OPENGL
        mImplementation = std::unique_ptr<ShaderImplement>{new ShaderOpenGL{std::move(vertexFile),std::move(fragmentFile)}};

#else
#error "only openGl is supoorted so far"
#endif
    }

    void Shader::Bind() {
        {
            mImplementation->Bind();
        }
    }



}

//
// Created by Prasanga Tiwari on 5/12/24.
//

#ifndef YOURPROJECTNAME_SHADER_H
#define YOURPROJECTNAME_SHADER_H
#include "pch.h"
#include "utility.h"

namespace Ultimate {
    class Shader {
    public:
        Shader(const std::string& vertexFile, const std::string& fragmentFile) ;
        Shader(std::string&& vertexFile,  std::string&& fragmentFile);

        void Bind();

    private:
        std::unique_ptr<ShaderImplement> mImplementation;

    };

}
#endif //YOURPROJECTNAME_SHADER_H

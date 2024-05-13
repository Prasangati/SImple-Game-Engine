//
// Created by Prasanga Tiwari on 5/12/24.
//

#ifndef YOURPROJECTNAME_SHADER_H
#define YOURPROJECTNAME_SHADER_H
#include "pch.h"
#include "utility.h"
#include "ShaderImplement.h"
namespace Ultimate {
    class Shader {
    public:
        Shader(const std::string& vertexFile, const std::string& fragmentFile) ;
        Shader(std::string&& vertexFile,  std::string&& fragmentFile);

        void Bind();

        void SetUniform2Ints(const std::string& uniformName, int val1, int val2);
        void SetUniform2Ints(std::string&& uniformName, int val1, int val2);

    private:
        std::unique_ptr<ShaderImplement> mImplementation;

    };

}
#endif //YOURPROJECTNAME_SHADER_H

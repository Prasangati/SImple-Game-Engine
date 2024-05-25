//
// Created by tiwari on 5/12/2024.
//
#include "pch.h"
#include "utility.h"
#include "ShaderOpenGL.h"
#include "glad/glad.h"

namespace Ultimate {
    ShaderOpenGL::ShaderOpenGL(const std::string &vertexFile, const std::string &fragmentFile) {
        // Print current working directory
        std::cout << "Current working directory: " << std::filesystem::current_path() << std::endl;

        // Print the full paths of the shader files
        std::cout << "Vertex shader file path: " << std::filesystem::absolute(vertexFile) << std::endl;
        std::cout << "Fragment shader file path: " << std::filesystem::absolute(fragmentFile) << std::endl;

        // Read vertex shader code
        std::string vertexShaderCode = ReadFile(vertexFile);
        if (vertexShaderCode.empty()) return;
        const char* vertexShaderSource = vertexShaderCode.c_str();
        std::cout << "Vertex Shader Source:\n" << vertexShaderCode << std::endl;

        // Read fragment shader code
        std::string fragmentShaderCode = ReadFile(fragmentFile);
        if (fragmentShaderCode.empty()) return;
        const char* fragmentShaderSource = fragmentShaderCode.c_str();
        std::cout << "Fragment Shader Source:\n" << fragmentShaderCode << std::endl;

        // Compile vertex shader
        unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
        glCompileShader(vertexShader);
        int success;
        char infoLog[512];
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
            ULTIMATE_ERROR("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog);
            std::cerr << "Vertex Shader Compilation Log: " << infoLog << std::endl;
        }

        // Compile fragment shader
        unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
        glCompileShader(fragmentShader);
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
            ULTIMATE_ERROR("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog);
            std::cerr << "Fragment Shader Compilation Log: " << infoLog << std::endl;
        }

        // Link shaders into a program
        mShaderProg = glCreateProgram();
        glAttachShader(mShaderProg, vertexShader);
        glAttachShader(mShaderProg, fragmentShader);
        glLinkProgram(mShaderProg);
        glGetProgramiv(mShaderProg, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(mShaderProg, 512, NULL, infoLog);
            ULTIMATE_ERROR("ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog);
            std::cerr << "Shader Program Linking Log: " << infoLog << std::endl;
        }

        // Clean up shaders as they are now linked into the program
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    }

    ShaderOpenGL::ShaderOpenGL(std::string &&vertexFile, std::string &&fragmentFile) {
        std::string vertexShaderCode = ReadFile(std::move(vertexFile));
        const char* vertexShaderSource = vertexShaderCode.c_str();

        std::string fragmentShaderCode = ReadFile(std::move(fragmentFile));
        const char* fragmentShaderSource = fragmentShaderCode.c_str();

        unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
        glCompileShader(vertexShader);
        int success;
        char infoLog[512];
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
            ULTIMATE_ERROR("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog);
            std::cerr << "Vertex Shader Compilation Log: " << infoLog << std::endl;
        }

        unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
        glCompileShader(fragmentShader);
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
            ULTIMATE_ERROR("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog);
            std::cerr << "Fragment Shader Compilation Log: " << infoLog << std::endl;
        }

        mShaderProg = glCreateProgram();
        glAttachShader(mShaderProg, vertexShader);
        glAttachShader(mShaderProg, fragmentShader);
        glLinkProgram(mShaderProg);
        glGetProgramiv(mShaderProg, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(mShaderProg, 512, NULL, infoLog);
            ULTIMATE_ERROR("ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog);
            std::cerr << "Shader Program Linking Log: " << infoLog << std::endl;
        }

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    }

    ShaderOpenGL::~ShaderOpenGL() {
        glDeleteProgram(mShaderProg);
    }

    void ShaderOpenGL::Bind() {
        glUseProgram(mShaderProg);
    }

    std::string ShaderOpenGL::ReadFile(const std::string &fileName) {
        std::ifstream file(fileName);
        if (!file.is_open()) {
            ULTIMATE_ERROR("Failed to open file: " << fileName);
            std::cerr << "Failed to open file: " << fileName << std::endl;
            return "";
        }
        std::stringstream buffer;
        buffer << file.rdbuf();
        return buffer.str();
    }

    std::string ShaderOpenGL::ReadFile(std::string &&fileName) {
        std::ifstream file(std::move(fileName));
        if (!file.is_open()) {
            ULTIMATE_ERROR("Failed to open file: " << fileName);
            std::cerr << "Failed to open file: " << fileName << std::endl;
            return "";
        }
        std::stringstream buffer;
        buffer << file.rdbuf();
        return buffer.str();
    }

    void ShaderOpenGL::SetUniform2Ints(const std::string &uniformName, int val1, int val2) {
        glUseProgram(mShaderProg);
        GLuint location = glGetUniformLocation(mShaderProg, uniformName.c_str());
        glUniform2i(location, val1, val2);
    }

    void ShaderOpenGL::SetUniform2Ints(std::string &&uniformName, int val1, int val2) {
        glUseProgram(mShaderProg);
        GLuint location = glGetUniformLocation(mShaderProg, uniformName.c_str());
        glUniform2i(location, val1, val2);
    }
}

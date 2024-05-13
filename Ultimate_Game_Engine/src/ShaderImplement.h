//
// Created by tiwari on 5/12/2024.
//

#ifndef SHADERIMPLEMENT_H
#define SHADERIMPLEMENT_H


namespace{
class ShaderImplement {
public:
    virtual void Bind()=0;
    virtual void SetUniform2Ints(const std::string& uniformName, int val1, int val2) = 0;
    virtual void SetUniform2Ints(std::string&& uniformName, int val1, int val2) =0;

    virtual ~ShaderImplement(){};
};
}


#endif //SHADERIMPLEMENT_H

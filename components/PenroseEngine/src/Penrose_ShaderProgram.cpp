#include "Penrose_ShaderProgram.hpp"

#include <iostream>

using namespace Penrose;

ShaderProgram::ShaderProgram(const std::vector<std::unique_ptr<Shader>> &shaders) {
    program_id = glCreateProgram();
    for (auto it = shaders.begin(); it != shaders.end(); ++it) {
        glAttachShader(program_id, (*it)->getShaderID());
    }
    glLinkProgram(program_id);

    GLint program_success = GL_TRUE;
    glGetProgramiv(program_id, GL_LINK_STATUS, &program_success);
    if (program_success != GL_TRUE) {
        std:: cout << "Could not link program " << program_id << std::endl;
    }


}

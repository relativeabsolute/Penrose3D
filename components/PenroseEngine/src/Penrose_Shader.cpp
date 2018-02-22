#include "Penrose_Shader.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace Penrose;

std::unique_ptr<Shader> Shader::load_from_file(const std::string &file_name, GLenum shader_type) {
    GLuint shader_id = glCreateShader(shader_type);

    std::ifstream in_stream(file_name);
    if (!in_stream.good()) {
        std::cout << "Could not open file " << file_name << std::endl;
        return nullptr;
    }
    std::stringstream buffer;
    buffer << in_stream.rdbuf();

    std::string source_str = buffer.str();
    const GLchar* source_ptr = source_str.c_str();
    
    glShaderSource(shader_id, 1, &source_ptr, nullptr);

    glCompileShader(shader_id);

    GLint shader_compiled = GL_FALSE;
    glGetShaderiv(shader_id, GL_COMPILE_STATUS, &shader_compiled);

    if (shader_compiled != GL_TRUE) {
        std::cout << "Could not compile shader " << shader_id << std::endl;
        // TODO: report compilation error
        return nullptr;
    }
    
    std::unique_ptr<Shader> result = std::make_unique<Shader>();
    result->source = source_str;
    result->shader_id = shader_id;
    return result;
}

GLenum Shader::getShaderType() const {
    return shader_type;
}

GLuint Shader::getShaderID() const {
    return shader_id;
}

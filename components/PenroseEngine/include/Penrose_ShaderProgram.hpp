#ifndef PENROSE_SHADER_PROGRAM_HPP
#define PENROSE_SHADER_PROGRAM_HPP

#include "Penrose_Shader.hpp"
#include <vector>
#include <memory>

namespace Penrose {
    class ShaderProgram {
        public:
            ShaderProgram(const std::vector<std::unique_ptr<Shader>> &shaders);
        private:
            GLuint program_id;
    };
}

#endif

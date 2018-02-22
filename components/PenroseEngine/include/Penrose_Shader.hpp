#ifndef PENROSE_SHADER_HPP
#define PENROSE_SHADER_HPP

#include <string>
#include <memory>
#include <GL/glew.h>

namespace Penrose {
    class Shader {
        public:
            static std::unique_ptr<Shader> load_from_file(const std::string &file_name,
                GLenum shader_type);

            GLenum getShaderType() const;
            GLuint getShaderID() const;
        private:
            std::string source;
            GLuint shader_id;
            GLenum shader_type;
    };
}

#endif

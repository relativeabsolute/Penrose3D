#ifndef PENROSE_WINDOW_HPP
#define PENROSE_WINDOW_HPP

#include <SDL.h>
#include <string>

#include <GL/glew.h>
#include <SDL_opengl.h>

namespace Penrose {
    class Window {
        public:
            Window();
            Window(int width, int height);

            ~Window();

            bool init();

            std::string get_window_title() const;

            void set_window_title(const std::string &new_title);
        private:
            bool init_window_version(int major, int minor);
            bool init_window();
            bool init_gl();

            SDL_Window *win;
            SDL_GLContext gl_context;
            std::string window_title;
            int width, height;
    };
}

#endif

#ifndef PENROSE_WINDOW_HPP
#define PENROSE_WINDOW_HPP

#include <SDL.h>
#include <string>


namespace Penrose {
    class Window {
        public:
            Window();
            Window(int width, int height);
            ~Window();

            std::string get_window_title() const;

            void set_window_title(const std::string &new_title);
        private:
            SDL_Window *win;
            std::string window_title;
    };
}

#endif

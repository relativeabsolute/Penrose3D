#include "Penrose_Window.hpp"

using namespace Penrose;

Window::Window() : Window(1024, 768) {
}

Window::Window(int width, int height) {
    win = SDL_CreateWindow("Penrose_Window", 0, 0, width, height, SDL_WINDOW_SHOWN);

}

Window::~Window() {
    SDL_DestroyWindow(win);
}

std::string Window::get_window_title() const {
    return window_title;
}

void Window::set_window_title(const std::string &new_title) {
    window_title = new_title;
    const char *data = window_title.c_str();
    SDL_SetWindowTitle(win, data);
}

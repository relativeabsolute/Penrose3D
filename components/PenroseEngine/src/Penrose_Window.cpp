#include "Penrose_Window.hpp"

#include <iostream>

using namespace Penrose;

Window::Window() : Window(1024, 768) {
}

Window::Window(int width, int height)
    : width(width), height(height) {

}

Window::~Window() {
    SDL_DestroyWindow(win);
}

bool Window::init() {
    std::cout << "Attempting to set SDL gl attributes." << std::endl;
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
    std::cout << "SDL gl attributes set successfully." << std::endl;

    std::cout << "Attempting to create SDL gl window." << std::endl;
    win = SDL_CreateWindow("Penrose_Window", 0, 0, width, height,
            SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    if (!win) {
        std::cerr << "Error creating window: " << SDL_GetError() << std::endl;
        return false;
    }
    std::cout << "SDL gl window created successfully." << std::endl;

    return init_gl();
}

bool Window::init_gl() {
    std::cout << "Attempting to create SDL gl context." << std::endl;
    gl_context = SDL_GL_CreateContext(win);
    if (!gl_context) {
        std::cerr << "Error creating opengl context: " << SDL_GetError() << std::endl;
        return false;
    }
    std::cout << "SDL gl context created successfully." << std::endl;

    std::cout << "Attempting to initialize GLEW." << std::endl;
    glewExperimental = GL_TRUE;
    GLenum glew_error = glewInit();

    if (glew_error != GLEW_OK) {
        std::cerr << "Error initializing GLEW: " << glewGetErrorString(glew_error) << std::endl;
        return false;
    }
    std::cout << "GLEW initialized successfully." << std::endl;

    return true;
}

std::string Window::get_window_title() const {
    return window_title;
}

void Window::set_window_title(const std::string &new_title) {
    window_title = new_title;
    const char *data = window_title.c_str();
    SDL_SetWindowTitle(win, data);
}

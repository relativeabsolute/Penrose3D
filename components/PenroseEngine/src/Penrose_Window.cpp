#include "Penrose_Window.hpp"

#include <iostream>

#include "Penrose_Constants.hpp"

using namespace Penrose;

Window::Window() : Window(1024, 768) {
}

Window::Window(int width, int height)
    : width(width), height(height) {

}

Window::~Window() {
    SDL_DestroyWindow(win);
}

bool Window::init_window_version(int major, int minor) {
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, major);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, minor);

    std::cout << "Attempting to create SDL gl window with OpenGL version "
        << major << "." << minor << std::endl;
    win = SDL_CreateWindow("Penrose_Window", 0, 0, width, height,
            SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    if (!win) {
        std::cout << "Could not create SDL gl window with OpenGL version "
            << major << "." << minor << std::endl;
        return false;
    }
    std::cout << "SDL gl window created successfully." << std::endl;

    return true;
}

bool Window::init_window() {
    for (int major = GL_MAX_VERSION_MAJOR; major >= GL_MIN_VERSION_MAJOR; major--) {
        for (int minor = GL_MAX_VERSION_MINOR; minor >= GL_MIN_VERSION_MINOR; minor--) {
            if (init_window_version(major, minor)) {
                return true;
            }
        }
    }
    return false;
}

bool Window::init() {

    if (!init_window()) {
        std::cerr << "Minimum required OpenGL version " << GL_MIN_VERSION_MAJOR
            << "." << GL_MIN_VERSION_MINOR << " not supported on this system." << std::endl;
        return false;
    }

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

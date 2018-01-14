#include "Penrose_Application.hpp"
#include <iostream>

using namespace Penrose;

bool Application::init(const std::string &title) {
    quit = false;
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init error: " << SDL_GetError() << std::endl;
        return false;
    }
    window = std::make_unique<Window>();
    window->set_window_title(title);
    return true;
}

void Application::run() {

    while (!quit) {
        handle_events();
    }

}

void Application::handle_events() {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            quit = true;
        }
    }
}

#include "Penrose_Application.hpp"
#include <iostream>

using namespace Penrose;

bool Application::init(const std::string &title) {
    quit = false;
    std::cout << "Attempting to intialize SDL video." << std::endl;
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init error: " << SDL_GetError() << std::endl;
        return false;
    }
    std::cout << "Successfully initialized SDL video." << std::endl;
    window = std::make_unique<Window>();

    std::cout << "Attempting to create Window." << std::endl;
    if (!window->init()) {
        std::cerr << "Error creating window." << std::endl;
        return false;
    }
    std::cout << "Window created successfully." << std::endl;

    window->set_window_title(title);
    return true;
}

void Application::run() {

    std::cout << "Starting application run loop." << std::endl;
    while (!quit) {
        handle_events();
    }

    std::cout << "Ending application run loop." << std::endl;
}

void Application::handle_events() {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            std::cout << "Received SDL quit event." << std::endl;
            quit = true;
        }
    }
}

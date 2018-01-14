#ifndef PENROSE_APPLICATION_HPP
#define PENROSE_APPLICATION_HPP

#include <string>
#include <memory>
#include "Penrose_Window.hpp"

namespace Penrose {
    class Application {
        public:
            // TODO: maybe make use of error codes or exceptions in the future
            bool init(const std::string &title);

            void run();
        private:
            void handle_events();

            std::unique_ptr<Window> window;
            bool quit;
    };
}

#endif

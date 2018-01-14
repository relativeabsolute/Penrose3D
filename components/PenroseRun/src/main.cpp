#include <Penrose_Application.hpp>
#include <iostream>

int main(int argc, char *argv[]) {
    Penrose::Application app;
    if (!app.init("Penrose")) {
        std::cerr << "Something went wrong." << std::endl;
        return 1;
    }
    app.run();

    
    return 0;
}

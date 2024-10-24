#include "libs.h"

int main() {
    try {
        Menu menu;
        menu.handleInput();
    }
    catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
    return 0;
}
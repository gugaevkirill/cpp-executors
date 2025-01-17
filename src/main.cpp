#include <iostream>
#include <string>

#include "ExecutorsConfig.h"
#include "thread_pool/thread_pool.h"
#include "process_pool/process_pool.h"


namespace Executors {

std::string get_build_version() {
    return std::to_string(BUILD_VERSION_MAJOR) + "." + std::to_string(BUILD_VERSION_MINOR);
}

std::string get_user_input(std::string_view prompt) {
    std::cout << prompt << std::endl;

    std::string user_input;
    std::getline(std::cin >> std::ws, user_input);
    return user_input;
}

}


int main() {
    using namespace std::string_literals;
    using namespace Executors;

    // Report version
    std::cout << "Build version: " << get_build_version() << std::endl;

    // Test imports
    Dummy1 d1 {};
    Dummy2 d2 {};

    // Test user input function
    std::string inp { get_user_input("Enter something:") };
    std::cout << "You entered: " << inp << std::endl;

    return EXIT_SUCCESS;
}

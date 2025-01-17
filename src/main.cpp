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
    using namespace Executors;

    // Report version
    std::cout << "Build version: " << get_build_version() << std::endl;

    // Test ThreadPoolExecutor
    ThreadPoolExecutor thread_pool {};
    std::vector<int> map_results { thread_pool.map<int, int>(
        [](int x) { return x * x; },
        {1, 2, 3, 4, 5}
    ) };

    std::cout << "ThreadPoolExecutor.map results: [\n";
    for (auto result : map_results) {
        std::cout << "    " << result << ",\n";
    }
    std::cout << "]" << std::endl;

    return EXIT_SUCCESS;
}

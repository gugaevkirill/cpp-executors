cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Executors VERSION 1.0)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file(ExecutorsConfig.h.in ExecutorsConfig.h)

add_executable(Executors src/main.cpp)

# add the binary tree to the search path for include files
# so that we will find ExecutorsConfig.h
target_include_directories(Executors PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_BINARY_DIR}/src/thread_pool"
                           "${PROJECT_BINARY_DIR}/src/process_pool"
)

# Libraries
add_subdirectory(src/thread_pool)
add_subdirectory(src/process_pool)

target_link_libraries(Executors PUBLIC ThreadPool ProcessPool)

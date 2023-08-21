
cmake_minimum_required(VERSION 3.14)
project (simpleCLI LANGUAGES CXX)
find_package(Threads REQUIRED)

add_subdirectory(./External)
add_executable(simplecli ./simplecli/main.cpp)
target_link_libraries(simplecli PRIVATE simpleREPL)
target_link_libraries(simplecli PRIVATE Threads::Threads)

cmake_minimum_required(VERSION 4.3.1)

add_executable(fraction fraction.cpp
        fraction.hpp main.cpp)

target_compile_options(fraction PRIVATE -Wall -Wextra)
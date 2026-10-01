cmake_minimum_required(VERSION 3.16)

project(oving5)

set(CMAKE_CXX_STANDARD 17)

add_executable(oppgave1-poly oppgave1-poly.cpp)

target_compile_options(oppgave1-poly PRIVATE -Wall -Wextra)
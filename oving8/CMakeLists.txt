cmake_minimum_required(VERSION 3.16)

project(oving8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(oving8-oppgave1 oppgave1.cpp)
add_executable(oving8-oppgave2 oppgave2.cpp pair.hpp)

target_compile_options(oving8-oppgave1 PRIVATE -Wall -Wextra)
target_compile_options(oving8-oppgave2 PRIVATE -Wall -Wextra)

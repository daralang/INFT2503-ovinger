cmake_minimum_required(VERSION 4.3.1)

add_executable(oppgave2 oppgave2.cpp
        oppgave1.hpp)
add_executable(oppgave3 oppgave3.cpp
        commodity.hpp
        commodity.cpp)


target_compile_options(oppgave2 PRIVATE -Wall -Wextra)
target_compile_options(oppgave3 PRIVATE -Wall -Wextra)



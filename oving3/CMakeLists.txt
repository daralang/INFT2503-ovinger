cmake_minimum_required(VERSION 4.3.1)

add_executable(oppgave2 oppgave2.cpp
        oppgave1.h)


target_compile_options(oppgave2 PRIVATE -Wall -Wextra)


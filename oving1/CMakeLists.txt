cmake_minimum_required(VERSION 4.4)

add_executable(oppgave-a oppgave-a.cpp)
add_executable(oppgave-b oppgave-b.cpp)

target_compile_options(oppgave-a PRIVATE -Wall -Wextra)
target_compile_options(oppgave-b PRIVATE -Wall -Wextra)
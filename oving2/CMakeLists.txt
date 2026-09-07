cmake_minimum_required(VERSION 3.16)

project(oving2)

set(CMAKE_CXX_STANDARD 17)

add_executable(oppgave1 oppgave1.cpp)
add_executable(oppgave4 oppgave4.cpp)
add_executable(oppgave5 oppgave5.cpp)
add_executable(oppgave6 oppgave6.cpp)

target_compile_options(oppgave1 PRIVATE -Wall -Wextra)
target_compile_options(oppgave4 PRIVATE -Wall -Wextra)
target_compile_options(oppgave5 PRIVATE -Wall -Wextra)
target_compile_options(oppgave6 PRIVATE -Wall -Wextra)
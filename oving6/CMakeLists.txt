cmake_minimum_required(VERSION 3.16)

project(oving6)

set(CMAKE_CXX_STANDARD 17)

add_executable(oppgave1-chess
        oppgave1-chess.cpp
        ChessBoardPrint.cpp
)
find_package(Boost REQUIRED)

add_executable(oppgave2-server
        oppgave2-server.cpp
)

target_include_directories(oppgave2-server PRIVATE
        ${Boost_INCLUDE_DIRS}
)

target_link_libraries(oppgave2-server PRIVATE
        ${Boost_LIBRARIES}
)

target_include_directories(oppgave1-chess PRIVATE ../oving5)

target_compile_options(oppgave1-chess PRIVATE -Wall -Wextra)
target_compile_options(oppgave2-server PRIVATE -Wall -Wextra)
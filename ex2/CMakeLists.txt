cmake_minimum_required(VERSION 3.29)
project(ex2)

set(CMAKE_CXX_STANDARD 11)

add_executable(ex2 main.cpp
        Game.cpp
        Game.h
        Player.cpp
        Player.h
        Board.cpp
        Board.h
        MoveValidator.cpp
        MoveValidator.h
)

cmake_minimum_required(VERSION 3.29)
project(minesweeper)

set(CMAKE_CXX_STANDARD 20)

add_executable(minesweeper main.cpp
        cell.cpp
        cell.h
        board.cpp
        board.h
)

cmake_minimum_required(VERSION 3.30)
project(ASS_3)

set(CMAKE_CXX_STANDARD 20)

add_executable(ASS_3 
    Main.cpp
    XO_game/XO_Classes.cpp
    Numerical_game9/Numerical_Board.cpp
    Numerical_game9/Numerical_UI.cpp
    Numerical_game9/Numerical_PlayManagement.cpp
)

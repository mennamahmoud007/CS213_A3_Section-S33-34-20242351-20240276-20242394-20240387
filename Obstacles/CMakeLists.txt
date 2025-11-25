# CMake configuration for the Obstacles Tic-Tac-Toe game

set(OBSTACLES_SRC
    Obstacles_Board.cpp
    Obstacles_Board.h
    Obstacles_UI.cpp
    Obstacles_UI.h
)

add_library(Obstacles STATIC ${OBSTACLES_SRC})

target_include_directories(Obstacles PRIVATE ${CMAKE_SOURCE_DIR}/Framework)
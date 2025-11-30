# CMake configuration for the Pyramid Tic-Tac-Toe game

set(PYRAMID_SRC
    Pyramid_Board.cpp
    Pyramid_Board.h
    Pyramid_UI.cpp
    Pyramid_UI.h
)

add_library(Pyramid STATIC ${PYRAMID_SRC})

target_include_directories(Pyramid PRIVATE ${CMAKE_SOURCE_DIR}/Framework)
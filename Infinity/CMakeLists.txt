# CMake configuration for the Infinity game

set(Infinity_SRC
    Infinity_Board.cpp
    Infinity_Board.h
    Infinity_UI.cpp
    Infinity_UI.h
)

add_library(Infinity STATIC ${Infinity_SRC})

target_include_directories(Infinity PRIVATE ${CMAKE_SOURCE_DIR}/Framework)

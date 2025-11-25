# CMake configuration for the Misere game

set(MISERE_SRC
    Misere_Board.cpp
    Misere_Board.h
    Misere_UI.cpp
    Misere_UI.h
)

add_library(Misere STATIC ${MISERE_SRC})

target_include_directories(Misere PRIVATE ${CMAKE_SOURCE_DIR}/Framework)
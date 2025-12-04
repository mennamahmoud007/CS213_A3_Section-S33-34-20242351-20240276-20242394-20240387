# FourInARow CMake configuration

set(FOURINAROW_SRC
    FourInARow_Board.cpp
    FourInARow_Board.h
    FourInARow_UI.cpp
    FourInARow_UI.h
)


add_library(FourInARow STATIC ${FOURINAROW_SRC})


target_include_directories(FourInARow PRIVATE ${CMAKE_SOURCE_DIR}/Framework)

# CMake configuration for the Diamond game

set(Diamond_SRC
        Diamond_Board.cpp
        Diamond_Board.h
        Diamond_UI.cpp
        Diamond_UI.h
)

add_library(Diamond STATIC ${Diamond_SRC})

target_include_directories(Diamond PRIVATE ${CMAKE_SOURCE_DIR}/Framework)

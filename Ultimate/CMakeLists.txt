# CMake configuration for the Ultimate game

set(Ultimate_SRC
    Ultimate_Board.cpp
    Ultimate_Board.h
    Ultimate_UI.cpp
    Ultimate_UI.h
)

add_library(Ultimate STATIC ${Ultimate_SRC})

target_include_directories(Ultimate PRIVATE ${CMAKE_SOURCE_DIR}/Framework)

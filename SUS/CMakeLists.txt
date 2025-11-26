# CMake configuration for the SUS game

set(SUS_SRC
    SUS_Board.cpp
    SUS_Board.h
    SUS_UI.cpp
    SUS_UI.h 
)
 
add_library(SUS STATIC ${SUS_SRC})

target_include_directories(SUS PRIVATE ${CMAKE_SOURCE_DIR}/Framework)
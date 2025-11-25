# CMake configuration for the Five By Five game

set(FIVEBYFIVE_SRC
    FiveByFive_Board.cpp
    FiveByFive_Board.h
    FiveByFive_UI.cpp
    FiveByFive_UI.h
)

add_library(FiveByFive STATIC ${FIVEBYFIVE_SRC})

target_include_directories(FiveByFive PRIVATE ${CMAKE_SOURCE_DIR}/Framework)
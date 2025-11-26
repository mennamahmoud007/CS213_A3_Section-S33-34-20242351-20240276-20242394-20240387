# Create FiveByFive library
set(FIVEBYFIVE_SRC
    FiveByFive_Board.cpp
    FiveByFive_Board.h
    FiveByFive_UI.cpp
    FiveByFive_UI.h
)

add_library(FiveByFive STATIC ${FIVEBYFIVE_SRC})

# Include directories
target_include_directories(FiveByFive PRIVATE ${CMAKE_SOURCE_DIR}/Framework)
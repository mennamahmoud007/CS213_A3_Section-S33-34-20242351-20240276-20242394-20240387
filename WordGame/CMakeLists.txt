set(WORDGAME_SRC
    Word_Board.cpp
    Word_Board.h
    Word_Board_UI.cpp
    Word_Board_UI.h
)

add_library(WordGame STATIC ${WORDGAME_SRC})
target_include_directories(WordGame PRIVATE ${CMAKE_SOURCE_DIR}/Framework)
set(WORDGAME_SRC
    Word_Board.cpp
    Word_Board_UI.cpp
)

add_library(WordGame STATIC ${WORDGAME_SRC})
target_include_directories(WordGame PRIVATE ${CMAKE_SOURCE_DIR}/Framework)
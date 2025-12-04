set(ULTIMATE_SRC
    Ultimate_Board.cpp
    Ultimate_Board_UI.cpp
)

add_library(Ultimate STATIC ${ULTIMATE_SRC})
target_include_directories(Ultimate PRIVATE ${CMAKE_SOURCE_DIR}/Framework)
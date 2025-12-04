# CMake configuration for the Memory game


set(MEMORY_SRC
    Memory_Board.cpp
    Memory_Board.h
    Memory_UI.cpp
    Memory_UI.h
)

add_library(Memory STATIC ${MEMORY_SRC})

target_include_directories(Memory PRIVATE ${CMAKE_SOURCE_DIR}/Framework)
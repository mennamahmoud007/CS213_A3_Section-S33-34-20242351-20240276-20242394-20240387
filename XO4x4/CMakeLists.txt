# CMake configuration for the XO4x4 game

#file(GLOB XO4x4_SOURCES "*.cpp")
#add_executable(XO4x4 ${XO4x4_SOURCES})
#add_library(XO4x4 ${XO4x4_SOURCES})

set(XO4x4_SRC
    XO4x4_Board.cpp
    XO4x4_Board.h
    XO4x4_UI.cpp
    XO4x4_UI.h
)

add_library(XO4x4 STATIC ${XO4x4_SRC})

target_include_directories(XO4x4 PRIVATE ${CMAKE_SOURCE_DIR}/Framework)
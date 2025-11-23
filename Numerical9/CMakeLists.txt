# CMake configuration for the Numerical9 game

#file(GLOB NUMERICAL9_SOURCES "*.cpp")
#add_executable(Numerical9 ${NUMERICAL9_SOURCES} "Numerical_Board.cpp")
#add_library(Numerical9 ${NUMERICAL9_SOURCES})

set(NUMERICAL9_SRC
    Numerical_Board.cpp
    Numerical_Board.h
    Numerical_UI.cpp
    Numerical_UI.h
)

add_library(Numerical9 STATIC ${NUMERICAL9_SRC})

target_include_directories(Numerical9 PRIVATE ${CMAKE_SOURCE_DIR}/Framework)
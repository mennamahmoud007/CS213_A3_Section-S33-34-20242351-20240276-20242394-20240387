cmake_minimum_required(VERSION 3.10)

project(BoardGamesProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Framework (shared classes)
include_directories(${CMAKE_SOURCE_DIR}/Framework)

# Add game modules
add_subdirectory(XO)
add_subdirectory(Numerical9)
add_subdirectory(Misere)
add_subdirectory(XO4x4) 
add_subdirectory(Obstacles)
add_subdirectory(FiveByFive) 
add_subdirectory(Infinity)
add_subdirectory(SUS)
add_subdirectory(WordGame)
add_subdirectory(Ultimate)



# MAIN MENU executable 
add_executable(BoardGames Main.cpp "WordGame /Word_Board.cpp" "WordGame /Word_Board.h" "WordGame /Word_Board_UI.cpp" "WordGame /Word_Board_UI.h"  "Ultimate /Ultimate_Board.cpp" "Ultimate /Ultimate_Board.h" "Ultimate /Ultimate_Board_UI.cpp" "Ultimate /Ultimate_Board_UI.h")
# Link the libraries from games
target_link_libraries(BoardGames PRIVATE XO Numerical9 Misere XO4x4 Obstacles FiveByFive Infinity SUS WordGame Ultimate)


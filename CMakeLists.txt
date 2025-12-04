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
add_subdirectory(FourInARow)
add_subdirectory(Memory)
add_subdirectory(Diamond)
add_subdirectory(Ultimate)
add_subdirectory(Pyramid)
add_subdirectory(WordGame)


# MAIN MENU executable 
add_executable(BoardGames Main.cpp)

# Link the libraries from games
target_link_libraries(BoardGames PRIVATE XO Numerical9 Misere XO4x4 Obstacles FiveByFive Infinity SUS FourInARow Memory Diamond Ultimate Pyramid WordGame)


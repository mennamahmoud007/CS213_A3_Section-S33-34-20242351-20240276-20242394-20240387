cmake_minimum_required(VERSION 3.10)

project(BoardGamesProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/Framework)

add_subdirectory(XO)
add_subdirectory(Numerical9)
add_subdirectory(Misere)
add_subdirectory(SUS)

add_executable(BoardGames Main.cpp)

target_link_libraries(BoardGames PRIVATE XO Numerical9 Misere SUS)

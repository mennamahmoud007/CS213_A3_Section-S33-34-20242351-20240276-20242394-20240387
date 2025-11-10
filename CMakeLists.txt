cmake_minimum_required(VERSION 3.30)
project(ASS_3)

set(CMAKE_CXX_STANDARD 20)


file(GLOB SOURCES "XO_game/*.cpp")

add_executable(ASS_3 ${SOURCES})
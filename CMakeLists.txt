# CMakeLists.txt for SUS

# Declare a library target named SUS
add_library(SUS
    SUS_Board.cpp
    SUS_UI.cpp
    SUS_Board.h
    SUS_UI.h
    SUS_Move.h
)

# Include current directory for headers
target_include_directories(SUS PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_features(SUS PUBLIC cxx_std_17)

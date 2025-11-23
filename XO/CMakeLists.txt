# Create an executable named XO using all .cpp in this folder
#file(GLOB XO_SOURCES "*.cpp")
#add_executable(XO ${XO_SOURCES})
#add_library(XO ${XO_SOURCES})

set(XO_SRC XO_Classes.cpp XO_Classes.h)
add_library(XO STATIC ${XO_SRC})

# Make sure the XO target can see the framework headers
target_include_directories(XO PRIVATE ${CMAKE_SOURCE_DIR}/Framework)
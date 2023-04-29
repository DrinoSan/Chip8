cmake_minimum_required(VERSION 3.10)

project(MyProject)

set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(src)

# Source files
file(GLOB SOURCES "src/*.cpp")

# Executable
add_executable(MyProject 
    main.cpp 
    ${SOURCES}
)


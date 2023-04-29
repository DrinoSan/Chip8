cmake_minimum_required(VERSION 3.10)

project(MyProject)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 17)

# Find SDL2 library
find_package(SDL2 REQUIRED)

# Include directories
include_directories(${SDL2_INCLUDE_DIRS} src)

# Source files
file(GLOB SOURCES "src/*.cpp")

# Executable
add_executable(MyProject 
    main.cpp 
    ${SOURCES}
)

# Link SDL2 library
target_link_libraries(MyProject ${SDL2_LIBRARIES})


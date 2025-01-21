cmake_minimum_required(VERSION 3.10)
project(expression-eval)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)

# Collect all source files
file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.h")

# Add the executable
add_executable(output ${SOURCES} ${HEADERS})
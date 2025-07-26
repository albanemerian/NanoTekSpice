cmake_minimum_required(VERSION 3.10)
project(nanotekspice)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source files
file(GLOB_RECURSE SOURCES
    "src/*.cpp"
    "src/*.hpp"
)

# Create executable
add_executable(nanotekspice ${SOURCES})

# Add include directories
target_include_directories(nanotekspice PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/src
)

# Set compilation flags
if (CMAKE_COMPILER_IS_GNUCXX)
    target_compile_options(nanotekspice PRIVATE -Wall -Wextra -Werror)
endif()

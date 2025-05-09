cmake_minimum_required(VERSION 3.10)
project(main CXX )

# Use C++11 (or higher if you prefer)
set(CMAKE_CXX_STANDARD 17)

# Find OpenCV installed on the system
find_package(OpenCV REQUIRED)

find_package(MAVSDK REQUIRED)

#include my source files
include_directories(${CMAKE_SOURCE_DIR}/include)
file(GLOB SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)
# Add the executable (main.cpp is your source file)
add_executable(${PROJECT_NAME} main.cpp ${SOURCES})

# Link OpenCV libraries to your executable
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS} MAVSDK::mavsdk)

# Optional: Print OpenCV version during configuration
message(STATUS "OpenCV version: ${OpenCV_VERSION}")

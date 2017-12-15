cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(HelloWorld)

find_package(OpenCV REQUIRED)


include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(include headers)

link_directories(${OpenCV_LIBRARY_DIRS})


add_definitions(-std=c++0x -g -O0)

add_executable (HelloWorld src/main.cpp)

target_link_libraries(HelloWorld ${OpenCV_LIBRARIES})

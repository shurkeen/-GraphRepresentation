cmake_minimum_required(VERSION 3.16)
project(Graph)

set(CMAKE_CXX_STANDARD 20)


include_directories(include)
include_directories(${INCLUDE_DIRECTORIES})

add_executable(mainGraph 
	src/main.cpp 
	src/SetGraph.cpp
	src/MatrixGraph.cpp
	src/ListGraph.cpp
	src/ArcGraph.cpp)
add_test(mainGraph ./mainGraph)
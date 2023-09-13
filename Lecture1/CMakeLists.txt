cmake_minimum_required(VERSION 3.0)

project(lecture1)

add_executable(lecture1 main.cpp)

install(TARGETS lecture1 RUNTIME DESTINATION bin)

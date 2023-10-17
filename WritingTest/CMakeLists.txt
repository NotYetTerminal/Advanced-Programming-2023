cmake_minimum_required(VERSION 3.0)

project(writingtest)

add_executable(writingtest source.cpp)

install(TARGETS writingtest RUNTIME DESTINATION bin)

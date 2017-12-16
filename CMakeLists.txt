cmake_minimum_required(VERSION 3.9)
project(ballern CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

add_executable(ballern
  Parser.cpp
  ballern.cpp
)

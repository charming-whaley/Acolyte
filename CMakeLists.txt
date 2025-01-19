cmake_minimum_required(VERSION 3.30)
project(Acolyte)

set(CMAKE_CXX_STANDARD 20)

add_executable(Acolyte Source/main.cpp
        Source/tools.cpp
        Source/controller.cpp
        Source/functionality_controller.cpp)

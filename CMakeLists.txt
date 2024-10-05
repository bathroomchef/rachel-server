# Specify the minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Define the project name
project(HelloWorld)

# Add an executable target for the hello.c file
add_executable(hello1 hello.cpp)

install(TARGETS hello1)

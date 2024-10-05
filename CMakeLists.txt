# Specify the minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Define the project name
project(Server)

# Add an executable target for the hello.c file
add_executable(rachel_server server.cpp)

install(TARGETS rachel_server)

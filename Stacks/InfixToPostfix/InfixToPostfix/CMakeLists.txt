﻿# CMakeList.txt : CMake project for InfixToPostfix, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (InfixToPostfix "InfixToPostfix.cpp" "InfixToPostfix.h" "Stack.cpp" "Stack.h")

# TODO: Add tests and install targets if needed.

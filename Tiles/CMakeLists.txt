﻿cmake_minimum_required(VERSION 3.8)
project(Tiles)

add_executable(${PROJECT_NAME} src/main.cpp)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

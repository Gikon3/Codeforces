cmake_minimum_required(VERSION 3.8)
project(SumInBinaryTree)

add_executable(SumInBinaryTree src/main.cpp)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET SumInBinaryTree PROPERTY CXX_STANDARD 20)
endif()
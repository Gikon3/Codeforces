cmake_minimum_required(VERSION 3.8)
project("AppleTree")

add_executable(AppleTree src/main.cpp src/Tree.h src/Tree.cpp)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET AppleTree PROPERTY CXX_STANDARD 20)
endif()

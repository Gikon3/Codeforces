cmake_minimum_required (VERSION 3.8)
project(MakeThemOdd)
add_executable(MakeThemOdd src/main.cpp)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET MakeThemOdd PROPERTY CXX_STANDARD 20)
endif()

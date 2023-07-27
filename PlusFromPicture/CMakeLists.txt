cmake_minimum_required(VERSION 3.8)
project(PlusFromPicture)

add_executable(PlusFromPicture src/main.cpp src/plusCheck.cpp src/plusCheck.h)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET PlusFromPicture PROPERTY CXX_STANDARD 20)
endif()
cmake_minimum_required(VERSION 3.8)
project(LongLong)

add_executable(LongLong src/main.cpp)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET LongLong PROPERTY CXX_STANDARD 20)
endif()
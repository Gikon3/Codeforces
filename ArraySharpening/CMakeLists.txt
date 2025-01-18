cmake_minimum_required(VERSION 3.8)
project(ArraySharpening)

add_executable(${PROJECT_NAME} src/main.cpp)
set_target_properties(${PROJECT_NAME} PROPERTIES
	CXX_STANDARD 20
)

cmake_minimum_required(VERSION 3.20)
project(ArraySharpening)

add_executable(${PROJECT_NAME} "")
set_target_properties(${PROJECT_NAME} PROPERTIES
	CXX_STANDARD 20
)

enable_testing()

add_subdirectory(src)
add_subdirectory(test)

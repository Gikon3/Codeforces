cmake_minimum_required(VERSION 3.20)

set(tests
	data00.txt
)

set(answers_to_tests
	"YES\nNO\nYES\nNO\n"
)

list(LENGTH tests len)
math(EXPR len "${len} - 1")
foreach(i RANGE ${len})
	list(GET tests ${i} test)
	list(GET answers_to_tests ${i} answer)
	get_filename_component(test_name ${test} NAME_WE)
	add_test(NAME ${test_name}
		COMMAND
		${CMAKE_CURRENT_SOURCE_DIR}/script.sh ${CMAKE_BINARY_DIR}/${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/${test}
	)
	set_property(TEST ${test_name} PROPERTY PASS_REGULAR_EXPRESSION "^${answer}")
endforeach()

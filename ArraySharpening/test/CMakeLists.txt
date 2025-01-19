cmake_minimum_required(VERSION 3.20)

set(tests
	data00.txt
	data01.txt
	data02.txt
	data03.txt
	data04.txt
	data05.txt
	data06.txt
	data07.txt
	data08.txt
	data09.txt
	data10.txt
	data11.txt
	data12.txt
	data13.txt
	data14.txt
	data15.txt
	data16.txt
	data17.txt
	data18.txt
	data19.txt
)

set(answers_to_tests
	"Yes"
	"Yes"
	"Yes"
	"Yes\nYes\nYes\nYes\nYes\n"
	"No"
	"Yes"
	"Yes"
	"Yes"
	"No\nYes\nYes\nYes\nYes\n"
	"Yes"
	"No"
	"Yes"
	"Yes"
	"No"
	"No\nYes\nYes\nNo\nYes\nYes\nNo\n"
	"No"
	"No"
	"Yes"
	"Yes"
	"Yes"
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
	set_property(TEST ${test_name} PROPERTY PASS_REGULAR_EXPRESSION ${answer})
endforeach()

add_executable(test_eof src/test_eof.c)
add_executable(
	test_temperatures
	src/test_temperatures.c
)
add_executable(test_blanks src/test_blanks.c)

target_link_libraries(test_eof chapter1)
target_link_libraries(test_temperatures chapter1)
target_link_libraries(test_blanks chapter1)

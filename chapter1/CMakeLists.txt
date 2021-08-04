add_executable(
	hello_world
	src/hello.c
)
add_library(
	chapter1 SHARED
	src/eof.c
	src/fahrenheit.c
	src/celcius.c
	src/blanks.c
	src/histogram.c
)
target_include_directories(
	chapter1
	PUBLIC include
	PRIVATE src
)

file(GLOB SOURCES src/ex*.c)

include_directories(include)
add_library(utils SHARED src/utils.c)

foreach(ELEMENT ${SOURCES})
	get_filename_component(FILENAME ${ELEMENT} NAME_WE)
	add_executable(${FILENAME} ${ELEMENT})
endforeach()

target_link_libraries(ex13 utils)
target_link_libraries(ex14 utils)

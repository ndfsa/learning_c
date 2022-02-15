file(GLOB SOURCES src/ex*.c)

foreach(ELEMENT ${SOURCES})
    get_filename_component(FILENAME ${ELEMENT} NAME_WE)
    add_executable(ch2${FILENAME} ${ELEMENT})
endforeach()

target_link_libraries(ch2ex3 ch2utils)

file(GLOB SOURCES src/ex*.c)

foreach(ELEMENT ${SOURCES})
    get_filename_component(FILENAME ${ELEMENT} NAME_WE)
    add_executable(${FILENAME} ${ELEMENT})
endforeach()

target_link_libraries(ex3-1 ch3utils)
target_link_libraries(ex3-2 ch3utils)
target_link_libraries(ex3-3 ch3utils)

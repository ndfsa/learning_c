file(GLOB SOURCES src/ex*.c)

foreach(ELEMENT ${SOURCES})
    get_filename_component(FILENAME ${ELEMENT} NAME_WE)
    add_executable(${FILENAME} ${ELEMENT})
    target_link_libraries(${FILENAME} ch4utils)
endforeach()

target_link_libraries(ex4-3 m)
target_link_libraries(ex4-4 m)
target_link_libraries(ex4-5 m)
target_link_libraries(ex4-6 m)
target_link_libraries(ex4-7 m)
target_link_libraries(ex4-8 m)
target_link_libraries(ex4-9 m)

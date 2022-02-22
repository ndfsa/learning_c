file(GLOB SOURCES src/ex*.c)

foreach(ELEMENT ${SOURCES})
    get_filename_component(FILENAME ${ELEMENT} NAME_WE)
    add_executable(${FILENAME} ${ELEMENT})
endforeach()

target_link_libraries(ex2-3 ch2utils)
target_link_libraries(ex2-4 ch2utils)
target_link_libraries(ex2-5 ch2utils)
target_link_libraries(ex2-6 ch2utils)
target_link_libraries(ex2-7 ch2utils)
target_link_libraries(ex2-8 ch2utils)
target_link_libraries(ex2-9 ch2utils)

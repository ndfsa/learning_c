file(GLOB SOURCES src/ex*.c)

foreach(ELEMENT ${SOURCES})
    get_filename_component(FILENAME ${ELEMENT} NAME_WE)
    add_executable(${FILENAME} ${ELEMENT})
    target_link_libraries(${FILENAME} ch1utils)
endforeach()

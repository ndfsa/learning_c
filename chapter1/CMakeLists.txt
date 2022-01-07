file(GLOB SOURCES src/ex*.c)

include_directories(include)
add_library(ch1utils SHARED src/ch1utils.c)

foreach(ELEMENT ${SOURCES})
    get_filename_component(FILENAME ${ELEMENT} NAME_WE)
    add_executable(${FILENAME} ${ELEMENT})
endforeach()

target_link_libraries(ex13 ch1utils)
target_link_libraries(ex14 ch1utils)
target_link_libraries(ex16 ch1utils)

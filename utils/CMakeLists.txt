add_library(ch1utils SHARED src/ch1utils.c)
add_library(ch2utils SHARED src/ch2utils.c)
add_library(ch3utils SHARED src/ch3utils.c)
add_library(ch4utils SHARED src/ch4utils.c)

target_link_libraries(ch3utils ch1utils)

target_include_directories(ch1utils PUBLIC include)
target_include_directories(ch2utils PUBLIC include)
target_include_directories(ch3utils PUBLIC include)
target_include_directories(ch4utils PUBLIC include)

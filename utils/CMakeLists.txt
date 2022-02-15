add_library(ch1utils SHARED src/ch1utils.c)
add_library(ch2utils SHARED src/ch2utils.c)
target_include_directories(ch1utils PUBLIC include)
target_include_directories(ch2utils PUBLIC include)

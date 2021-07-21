add_library(
  input_output SHARED
  src/eof_val.c
)

target_include_directories(
  input_output
  PUBLIC include
  PRIVATE src
)

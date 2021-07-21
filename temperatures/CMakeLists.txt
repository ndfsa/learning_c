add_library(
  temperatures SHARED
  src/celcius.c
  src/fahrenheit.c
)

target_include_directories(
  temperatures
  PUBLIC include
  PRIVATE src
)

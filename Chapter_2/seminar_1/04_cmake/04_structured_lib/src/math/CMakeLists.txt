file(GLOB_RECURSE SOURCES *.cpp *.c)
add_library(math STATIC ${SOURCES})
message("math include dir " ${CMAKE_CURRENT_SOURCE_DIR})

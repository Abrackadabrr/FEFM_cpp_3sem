file(GLOB_RECURSE SOURCES *.cpp *.c)
add_library(phys STATIC ${SOURCES})
message("phys include dir " ${CMAKE_CURRENT_SOURCE_DIR})
file(GLOB_RECURSE SOURCES *.cpp *.c)
add_library(math STATIC ${SOURCES})
target_compile_definitions(math PRIVATE USE_MY_MATH)
message("math include dir " ${CMAKE_CURRENT_SOURCE_DIR})

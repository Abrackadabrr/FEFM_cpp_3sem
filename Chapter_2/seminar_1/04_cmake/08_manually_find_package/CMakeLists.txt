# ВНИМАНИЕ: этот пример у вас не соберется, потому что здесь прописаны относительные пути
# специально для моей машины


cmake_minimum_required(VERSION 3.11)

set(CMAKE_CXX_FLAGS "-std=c++11 -g") # стандарты можно и просто флагом, не только отдельной командой

project(gmshdemo)
add_executable(${PROJECT_NAME} basic_test_of_gmsh.cpp)

# Если библиотеки нет, то её нужно собрать руками
# Затем необходимо прописать пути, где лежит бинарник и хедера
add_library(gmsh SHARED IMPORTED)
set_target_properties(gmsh PROPERTIES
    IMPORTED_LOCATION "/home/evgen/Work/InfoChair/fefm_cpp_2_level/FEFM_cpp_3sem/Chapter_2/gmsh_library/lib/libgmsh.so.4.13"
    INTERFACE_INCLUDE_DIRECTORIES "/home/evgen/Work/InfoChair/fefm_cpp_2_level/FEFM_cpp_3sem/Chapter_2/gmsh_library/include"
)
set(GMSH_LIBRARY gmsh)

target_link_libraries(${PROJECT_NAME} PUBLIC ${GMSH_LIBRARY})

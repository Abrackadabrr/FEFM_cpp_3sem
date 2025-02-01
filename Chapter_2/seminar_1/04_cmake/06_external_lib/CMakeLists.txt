cmake_minimum_required(VERSION 3.16)

project(cmake_project3)

add_executable(${PROJECT_NAME} main.cpp)

# Допустим, что у нас откуда-то есть библиотека и мы хотим её слинковать
set(LINK_LIBS ${CMAKE_CURRENT_SOURCE_DIR}/lib/libhello.a)
target_include_directories(${PROJECT_NAME} PUBLIC include/)
target_link_libraries(${PROJECT_NAME} ${LINK_LIBS})

# Вопрос: а всегда ли мы знаем, где лежит файл .а?

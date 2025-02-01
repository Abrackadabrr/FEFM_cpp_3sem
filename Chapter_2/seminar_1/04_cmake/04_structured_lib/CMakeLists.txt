cmake_minimum_required(VERSION 3.16)

project(cmake_project4)

add_subdirectory(src)

add_executable(${PROJECT_NAME} main.cpp)

# Можно указывать директорию, где лежат заголовочные файлы 
# Команда говорит компилятору, где их искать
# Это упростит инклюды
target_include_directories(${PROJECT_NAME} PUBLIC src)

# Если убрать эту директиву, то нужно будет писать полный путь до заголовочных файлов

# В Сmake есть условный оператор

set(USE_MY_MATH ON)

if(USE_MY_MATH)
    message("USAGE OF MY MATH")
    target_compile_definitions(${PROJECT_NAME} PRIVATE USE_MY_MATH) # При компиляции (-DUSE_MY_MATH=OFF)
endif()

message("USE_MY_MATH = ${USE_MY_MATH}")
target_link_libraries(${PROJECT_NAME} math phys)

# Снова о PRIVATE
# Если бы мы собирались дальше куда-то линковать нашу библиотеку 
# через target_link_libraries, то compile_definition -DUSE_MY_MATH=ON не
# будет установлено при компиляции этого таргета. PUBLIC -- будет установлено


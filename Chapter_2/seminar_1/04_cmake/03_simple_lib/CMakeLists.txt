cmake_minimum_required(VERSION 3.16)

project(cmake_project2)

set(LIBRARY hello.cpp)

add_executable(${PROJECT_NAME} main.cpp)

# Создаем статическую библиотеку
# Теперь она является вторым таргетом  
add_library(hello STATIC hello.cpp)

# Расскажем линкеру как соединить два таргета в один (слинковать библиотеку)
target_link_libraries(${PROJECT_NAME} hello)

# Полностью комадна выглядит вот так
# target_link_libraries(main [PRIVATE|PUBLIC|INTERFACE] hello)

# В предыдущем использовании команды по дефолту стоит PUBLIC
# Это означает, что функции из библиотеки будут торчать снаружи везде,
# куда мы захотим слинковать таргет ${PROJECT_NAME}

# Пример для PRIVATE:
# add_library(lib1 src1.cpp)
# add_library(lib2 src2.cpp)
# add_executable(main.cpp)
#target_link_libraries(lib1 PRIVATE lib2)
#target_link_libraries(main PRIVATE lib1) # main ничего не знает о lib2, функции не торчат


cmake_minimum_required(VERSION 3.14)

project(find_package_example)

add_executable(${PROJECT_NAME} main.cpp)

# Директива find_package позволяет буквально "найти пакет"
# установленный на вашей машине. Для этого подключаемая библиотека должна поддерживать 
# поиск через find_package. Это значит, что для неё созданы специальные конфигурационные файлы, 
# которые помещаются в системную директорию. Они содержат в себе информацию о том,
# где лежат бинарник и папка с хедерами

# Также find_package устанавилвает некоторые системные переменнные

find_package(OpenMP)

if (OPENMP_FOUND)
    message("OpenMP Found")
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE OpenMP::OpenMP_CXX)

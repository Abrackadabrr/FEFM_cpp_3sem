cmake_minimum_required(VERSION 3.16)

project(cmake_project4)

add_subdirectory(third_party)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC third_party)

set(USE_MY_MATH ON)

if(USE_MY_MATH)
    message("USAGE OF MY MATH")
endif()

message("USE_MY_MATH = ${USE_MY_MATH}")
target_link_libraries(${PROJECT_NAME} math phys)


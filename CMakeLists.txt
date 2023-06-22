cmake_minimum_required (VERSION 3.0)
project (database)

add_compile_options(-std=c++14)

include_directories(include)
add_executable(database src/main.cpp)
set_target_properties(database
                     PROPERTIES COMPILE_FLAGS "-g -Wall -Wextra")

target_link_libraries(database)
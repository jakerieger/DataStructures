cmake_minimum_required(VERSION 3.27)
project(DataStructures C)

set(CMAKE_C_STANDARD 11)

add_executable(tests tests.c
        linked_list.h
        linked_list.c
        stack.h
        stack.c)
find_package(unity REQUIRED)
target_link_libraries(tests PRIVATE unity)
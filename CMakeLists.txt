cmake_minimum_required(VERSION 3.27)
project(DataStructures C)

set(CMAKE_C_STANDARD 11)

set(TESTS_LIST
        test_binarytree
        test_doublelinkedlist
        test_hashmap
        test_linkedlist
        test_queue
        test_rope
        test_stack
        test_vector
)

set(TESTS_LIST_SOURCES
        binary_tree.c
        dbl_linked_list.c
        hash_map.c
        linked_list.c
        queue.c
        rope.c
        stack.c
        vector.c
)

set(TESTS_LIST_INCLUDES
        binary_tree.h
        dbl_linked_list.h
        hash_map.h
        linked_list.h
        queue.h
        rope.h
        stack.h
        vector.h
)

foreach (test src inc IN ZIP_LISTS TESTS_LIST TESTS_LIST_SOURCES TESTS_LIST_INCLUDES)
    add_executable(${test} "tests/${test}.c" "${src}" ${inc})
    find_package(unity REQUIRED)
    target_link_libraries(${test} PRIVATE unity)
endforeach ()
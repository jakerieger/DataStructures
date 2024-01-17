#include "linked_list.h"
#include "stack.h"
#include "binary_tree.h"
#include "queue.h"
#include "vector.h"

#include <stdint.h>
#include <unity/unity.h>

//====================================================//
//                  TEST FUNCTIONS                    //
//====================================================//
void Test_LinkedList(void) {
#define RESET_LIST(list, count, free)                                                              \
    do {                                                                                           \
        if (free)                                                                                  \
            listFree(list);                                                                        \
        for (uint8_t i = 0; i < count; i++) {                                                      \
            listPushBack(list, count*(i + 1));                                                     \
        }                                                                                          \
    } while (false)
#define NUM_VALUES 10

    TLinkedList list;
    listInit(&list);
    RESET_LIST(&list, NUM_VALUES, false);

    TEST_ASSERT_TRUE(list.count == NUM_VALUES);
    TEST_ASSERT_TRUE(listRemoveIndex(&list, 2));
    RESET_LIST(&list, NUM_VALUES, true);

    TEST_ASSERT_TRUE(listRemoveValue(&list, 20) == 1);
    RESET_LIST(&list, NUM_VALUES, true);

    int val;
    TEST_ASSERT_TRUE(listPop(&list, &val));
    TEST_ASSERT_TRUE(val == 10);
    RESET_LIST(&list, NUM_VALUES, true);

    TEST_ASSERT_TRUE(listPopBack(&list, &val));
    TEST_ASSERT_TRUE(val == 100);
    RESET_LIST(&list, NUM_VALUES, true);

    TEST_ASSERT_TRUE(listContains(&list, 30));
    TEST_ASSERT_TRUE(listContains(&list, 56) == false);
    RESET_LIST(&list, NUM_VALUES, true);

    TEST_ASSERT_TRUE(listGet(&list, 5, &val));
    TEST_ASSERT_TRUE(val == 60);

    listFree(&list);

#undef NUM_VALUES
#undef RESET_LIST
}

void Test_Stack(void) {
    TStack stack;
    TEST_ASSERT_TRUE(stackInit(&stack, 8) == 0);
    TEST_ASSERT_TRUE(stackPop(&stack) == -1);

    int size = stackPush(&stack, 42);
    TEST_ASSERT_TRUE(size == 1);
    TEST_ASSERT_TRUE(stackPop(&stack) == 42);
    TEST_ASSERT_TRUE(stack.size == 0);

    stackPush(&stack, 1);
    stackPush(&stack, 2);
    stackPush(&stack, 3);
    stackPush(&stack, 4);
    size = stackPush(&stack, 5);
    TEST_ASSERT_TRUE(size == 5);
    stackReset(&stack);
    TEST_ASSERT_TRUE(stack.size == 0);

    stackFree(&stack);
}

void Test_Queue(void) {
    TQueue queue;
    queueInit(&queue, 8);

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    enqueue(&queue, 4);
    enqueue(&queue, 5);
    enqueue(&queue, 6);
    enqueue(&queue, 7);
    enqueue(&queue, 8);
    TEST_ASSERT_TRUE(queue.size == 8);
    enqueue(&queue, 9);
    TEST_ASSERT_TRUE(queue.size == 9);
    int val;
    dequeue(&queue, &val);
    TEST_ASSERT_TRUE(val == 1);
    TEST_ASSERT_TRUE(queue.size == 8);
    dequeue(&queue, &val);
    dequeue(&queue, &val);
    dequeue(&queue, &val);
    TEST_ASSERT_TRUE(val == 4);

    queueFree(&queue);
}

void Test_Vector(void) {
    TVector vec;
    vecInit(&vec);

    vecPushBack(&vec, 1);
    vecPushBack(&vec, 2);
    vecPushBack(&vec, 3);
    vecPushBack(&vec, 4);
    vecPushBack(&vec, 5);
    TEST_ASSERT_EQUAL(vec.size, 5);
    vecPrint(&vec);

    int val;
    TEST_ASSERT_TRUE(vecAt(&vec, 2, &val));
    TEST_ASSERT_EQUAL(val, 3);

    TEST_ASSERT_TRUE(vecRemove(&vec, 2));
    vecPrint(&vec);
    TEST_ASSERT_EQUAL(vec.size, 4);
    TEST_ASSERT_TRUE(vecAt(&vec, 2, &val));
    TEST_ASSERT_EQUAL(val, 4);
    TEST_ASSERT_FALSE(vecAt(&vec, 10, &val));
    TEST_ASSERT_TRUE(vecContains(&vec, 1));
    TEST_ASSERT_FALSE(vecContains(&vec, 99));

    vecFree(&vec);
}

void Test_BinaryTree(void) {
    TBinaryTree tree;
    treeInit(&tree);

    TTreeNode node01 = {7, NULL, NULL};
    TTreeNode node0 = {6, NULL, NULL};
    TTreeNode node1 = {5, NULL, NULL};
    TTreeNode node2 = {4, NULL, NULL};
    TTreeNode node3 = {3, &node0, &node01};
    TTreeNode node4 = {2, &node2, &node1};
    TTreeNode node5 = {1, &node4, &node3};

    tree.root = &node5;
    treeContains(&tree, 5);

    treeFree(&tree);
}
//====================================================//
//                  --------------                    //
//====================================================//

void setUp(void) {}
void tearDown(void) {}

int main(int argc, char** argv) {
    UNITY_BEGIN();

    RUN_TEST(Test_LinkedList);
    RUN_TEST(Test_Stack);
    RUN_TEST(Test_Queue);
    RUN_TEST(Test_Vector);
    // RUN_TEST(Test_BinaryTree);

    return UNITY_END();
}
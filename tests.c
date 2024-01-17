#include "linked_list.h"
#include "stack.h"
#include <stdint.h>
#include <unity/unity.h>

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

    const int size = stackPush(&stack, 42);
    TEST_ASSERT_TRUE(size == 1);
    TEST_ASSERT_TRUE(stackPop(&stack) == 42);
    TEST_ASSERT_TRUE(stack.size == 0);

    stackPush(&stack, 1);
    stackPush(&stack, 2);
    stackPush(&stack, 3);
    stackPush(&stack, 4);
    stackPush(&stack, 5);
    stackReset(&stack);
    TEST_ASSERT_TRUE(stack.size == 0);

    stackFree(&stack);
}

void setUp(void) {}
void tearDown(void) {}

int main(int argc, char** argv) {
    UNITY_BEGIN();

    RUN_TEST(Test_LinkedList);
    RUN_TEST(Test_Stack);

    return UNITY_END();
}

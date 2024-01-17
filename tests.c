#include "linked_list.h"
#include <stdint.h>
#include <unity/unity.h>

void Test_LinkedList(void) {
#define RESET_LIST(list, count, free)                                                              \
    do {                                                                                           \
        if (free)                                                                                  \
            freeList(list);                                                                        \
        for (uint8_t i = 0; i < count; i++) {                                                      \
            push_back(list, count*(i + 1));                                                        \
        }                                                                                          \
    } while (false)
#define NUM_VALUES 10

    TLinkedList list;
    initList(&list);
    RESET_LIST(&list, NUM_VALUES, false);

    TEST_ASSERT_TRUE(list.count == NUM_VALUES);
    TEST_ASSERT_TRUE(removeAt(&list, 2));
    RESET_LIST(&list, NUM_VALUES, true);

    TEST_ASSERT_TRUE(removeValue(&list, 20) == 1);
    RESET_LIST(&list, NUM_VALUES, true);

    int val;
    TEST_ASSERT_TRUE(pop(&list, &val));
    TEST_ASSERT_TRUE(val == 10);
    RESET_LIST(&list, NUM_VALUES, true);

    TEST_ASSERT_TRUE(pop_back(&list, &val));
    TEST_ASSERT_TRUE(val == 100);
    RESET_LIST(&list, NUM_VALUES, true);

    TEST_ASSERT_TRUE(contains(&list, 30));
    TEST_ASSERT_TRUE(contains(&list, 56) == false);
    RESET_LIST(&list, NUM_VALUES, true);

    TEST_ASSERT_TRUE(get(&list, 5, &val));
    TEST_ASSERT_TRUE(val == 60);

    freeList(&list);

#undef NUM_VALUES
#undef RESET_LIST
}

void setUp(void) {}
void tearDown(void) {}

int main(int argc, char** argv) {
    UNITY_BEGIN();

    RUN_TEST(Test_LinkedList);

    return UNITY_END();
}

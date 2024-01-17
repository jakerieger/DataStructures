#include "linked_list.h"
#include <stdint.h>
#include <unity/unity.h>

void Test_LinkedList(void) {
#define NUM_VALUES 10
    TLinkedList list;
    initList(&list);

    for (uint8_t i = 0; i < NUM_VALUES; i++) {
        push_back(&list, NUM_VALUES * (i + 1));
    }

    TEST_ASSERT_TRUE(list.count == NUM_VALUES);

    freeList(&list);
#undef NUM_VALUES
}

void setUp(void) {}
void tearDown(void) {}

int main(int argc, char** argv) {
    UNITY_BEGIN();

    RUN_TEST(Test_LinkedList);

    return UNITY_END();
}

#include <stdio.h>
#include "../stack.h"
#include <unity/unity.h>
#include <unity/unity_fixture.h>

TEST_GROUP(Stack);

TStack stack;

TEST_SETUP(Stack) {}
TEST_TEAR_DOWN(Stack) {
    stackReset(&stack);
}

TEST(Stack, CreateStack) {
    TEST_ASSERT_TRUE(stackInit(&stack, 8));
}

TEST(Stack, PushStack) {
    TEST_ASSERT_EQUAL(stackPush(&stack, 1999), 1);
}

TEST(Stack, PopStack) {
    stackPush(&stack, 1999);
    int val;
    stackPop(&stack, &val);
    TEST_ASSERT_EQUAL(val, 1999);
}

TEST_GROUP_RUNNER(Stack) {
    RUN_TEST_CASE(Stack, CreateStack);
    RUN_TEST_CASE(Stack, PushStack);
    RUN_TEST_CASE(Stack, PopStack);
}

static void RunTests(void) {
    RUN_TEST_GROUP(Stack);
    stackFree(&stack);
}

int main(int argc, char** argv) {
    return UnityMain(argc, argv, RunTests);
}
#include <stdio.h>
#include "../vector.h"
#include <unity/unity.h>
#include <unity/unity_fixture.h>

TEST_GROUP(Vector);

TVector vec;

TEST_SETUP(Vector) {}
TEST_TEAR_DOWN(Vector) {
    vecClear(&vec);
}

TEST(Vector, CreateVector) {
    TEST_ASSERT_TRUE(vecInit(&vec));
}

TEST(Vector, PushBackSingle) {
    vecPushBack(&vec, 1999);
    TEST_ASSERT_EQUAL(vec.size, 1);
    TEST_ASSERT_EQUAL(vec.values[0], 1999);
}

TEST(Vector, PushBack10) {
    for (int i = 0; i < 10; i++) {
        vecPushBack(&vec, i);
    }
    for (int i = 0; i < 10; i++) {
        TEST_ASSERT_EQUAL(vec.values[i], i);
    }
}

TEST(Vector, PushBack100k) {
    for (int i = 0; i < 100000; i++) {
        vecPushBack(&vec, i);
    }
    for (int i = 0; i < 100000; i++) {
        TEST_ASSERT_EQUAL(vec.values[i], i);
    }
}

TEST(Vector, FromCArray) {
    int values[] = {1, 2, 3, 4, 5};
    TEST_ASSERT_TRUE(vecFrom(&vec, values, 5));
    for (int i = 0; i < 5; i++) {
        TEST_ASSERT_EQUAL(vec.values[i], values[i]);
    }
}

TEST_GROUP_RUNNER(Vector) {
    RUN_TEST_CASE(Vector, CreateVector);
    RUN_TEST_CASE(Vector, PushBackSingle);
    RUN_TEST_CASE(Vector, PushBack10);
    RUN_TEST_CASE(Vector, PushBack100k);
    RUN_TEST_CASE(Vector, FromCArray);
}

static void RunTests(void) {
    RUN_TEST_GROUP(Vector);
    vecFree(&vec);
}

int main(int argc, char** argv) {
    return UnityMain(argc, argv, RunTests);
}
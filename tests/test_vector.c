#include <stdio.h>
#include "../vector.h"
#include <unity/unity.h>
#include <unity/unity_fixture.h>

TEST_GROUP(Vector);

TVector vec;

TEST_SETUP(Vector) {}
TEST_TEAR_DOWN(Vector) {
    vecFree(&vec);
}

TEST(Vector, CreateVector) {
    TEST_ASSERT_TRUE(vecInit(&vec));
}

TEST_GROUP_RUNNER(Vector) {
    RUN_TEST_CASE(Vector, CreateVector);
}

static void RunTests(void) {
    RUN_TEST_GROUP(Vector);
}

int main(int argc, char** argv) {
    return UnityMain(argc, argv, RunTests);
}
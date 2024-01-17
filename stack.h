#pragma once
#include <stddef.h>

typedef struct Stack {
    int* stack;
    size_t capacity;
    size_t size;
} TStack;

int stackInit(TStack* stack, size_t initialCapacity);
int stackPush(TStack* stack, int value);
int stackPop(TStack* stack);
void stackReset(TStack* stack);
void stackFree(TStack* stack);
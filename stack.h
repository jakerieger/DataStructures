#pragma once
#include <stddef.h>
#include <stdbool.h>

typedef struct Stack {
    int* stack;
    size_t capacity;
    size_t size;
} TStack;

bool stackInit(TStack* stack, size_t initialCapacity);
int stackPush(TStack* stack, int value);
bool stackPop(TStack* stack, int* out);
void stackReset(TStack* stack);
void stackFree(TStack* stack);
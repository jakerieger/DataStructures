#pragma once
#include <stddef.h>

typedef struct Stack {
    int* stack;
    size_t capacity;
    size_t size;
} TStack;

void stackInit();
void stackPush();
void stackPop();
void stackReset();
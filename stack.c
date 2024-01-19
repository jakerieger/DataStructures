#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

bool stackInit(TStack* stack, const size_t initialCapacity) {
    stack->stack = (int*) malloc(sizeof(int) * initialCapacity);
    if (stack->stack == NULL) {
        return false;
    }

    stack->capacity = initialCapacity;
    stack->size = 0;
    return true;
}

int stackPush(TStack* stack, const int value) {
    if (stack->size == stack->capacity) {
        stack->capacity *= 2;
        stack->stack = (int*) realloc(stack->stack, stack->capacity * sizeof(int));
        if (stack->stack == NULL) {
            return -1;
        }
    }

    stack->stack[stack->size++] = value;
    return stack->size;
}

bool stackPop(TStack* stack, int* out) {
    if (stack->size > 0) {
        if (out != NULL) {
            *out = stack->stack[--stack->size];
        }
        return true;
    }

    // Stack underflow
    return false;
}

void stackReset(TStack* stack) {
    stack->size = 0;
}

void stackFree(TStack* stack) {
    free(stack->stack);
    stack->capacity = 0;
    stack->size = 0;
}
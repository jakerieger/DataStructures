#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

int stackInit(TStack* stack, const size_t initialCapacity) {
    stack->stack = (int*) malloc(sizeof(int) * initialCapacity);
    if (stack->stack == NULL) {
        fprintf(stderr, "Could not allocate stack\n");
        return 1;
    }

    stack->capacity = initialCapacity;
    stack->size = 0;
    return 0;
}

int stackPush(TStack* stack, const int value) {
    if (stack->size == stack->capacity) {
        stack->capacity *= 2;
        stack->stack = (int*)realloc(stack->stack, stack->capacity * sizeof(int));
        if (stack->stack == NULL) {
            fprintf(stderr, "Could not allocate stack\n");
            return -1;
        }
    }

    stack->stack[stack->size++] = value;
    return stack->size;
}

int stackPop(TStack* stack) {
    if (stack->size > 0) {
        return stack->stack[--stack->size];
    }

    // Stack underflow
    return -1;
}

void stackReset(TStack* stack) {
    stack->size = 0;
}

void stackFree(TStack* stack) {
    free(stack->stack);
    stack->capacity = 0;
    stack->size = 0;
}
#pragma once
#include <stddef.h>

typedef struct Queue {
    int* queue;
    size_t capacity;
    size_t size;
} TQueue;

void queueInit(TQueue* queue, size_t initialCapacity);
void enqueue(TQueue* queue, int value);
void dequeue(TQueue* queue, int* out);
void queueReset(TQueue* queue);
void queueFree(TQueue* queue);
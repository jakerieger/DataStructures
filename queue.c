#include "queue.h"

#include <stdlib.h>

void queueInit(TQueue* queue, size_t initialCapacity) {
    queue->queue = (int*) malloc(sizeof(int) * initialCapacity);
    queue->capacity = initialCapacity;
    queue->size = 0;
}

void enqueue(TQueue* queue, int value) {
    if (queue->size == queue->capacity) {
        queue->capacity *= 2;
        queue->queue = (int*) realloc(queue->queue, queue->capacity * sizeof(int));
    }
    queue->queue[queue->size++] = value;
}

void dequeue(TQueue* queue, int* out) {
    *out = queue->queue[0];
    --queue->size;
    for (int i = 0; i < queue->size; i++) {
        queue->queue[i] = queue->queue[i + 1];
    }
}

void queueReset(TQueue* queue) {
    queue->size = 0;
}

void queueFree(TQueue* queue) {
    free(queue->queue);
    queue->capacity = 0;
    queue->size = 0;
}
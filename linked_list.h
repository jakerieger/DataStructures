#pragma once

#include <stdbool.h>
#include <stdint.h>

typedef struct Node {
    int value;
    struct Node* next;
} TNode;

typedef struct LinkedList {
    TNode* head;
    uint32_t count;
} TLinkedList;

void initList(TLinkedList* list);
bool push(TLinkedList* list, int value);
bool push_back(TLinkedList* list, int value);
bool pop(TLinkedList* list, int* out);
bool pop_back(TLinkedList* list, int* out);
int removeValue(TLinkedList* list, int value);
bool removeAt(TLinkedList* list, int index);
bool contains(const TLinkedList* list, int value);
// TODO: Implement count of value in list
// bool countOf(TLinkedList* list, int value);
bool get(TLinkedList* list, int index, int* out);
void freeList(TLinkedList* list);
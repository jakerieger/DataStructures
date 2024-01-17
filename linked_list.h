#pragma once

#include <stdbool.h>
#include <stdint.h>

typedef struct ListNode {
    int value;
    struct ListNode* next;
} TListNode;

typedef struct LinkedList {
    TListNode* head;
    uint32_t count;
} TLinkedList;

void listInit(TLinkedList* list);
bool listPush(TLinkedList* list, int value);
bool listPushBack(TLinkedList* list, int value);
bool listPop(TLinkedList* list, int* out);
bool listPopBack(TLinkedList* list, int* out);
int listRemoveValue(TLinkedList* list, int value);
bool listRemoveIndex(TLinkedList* list, int index);
bool listContains(const TLinkedList* list, int value);
// TODO: Implement count of value in list
// bool countOf(TLinkedList* list, int value);
// TODO: Implement index of value in list
// int indexOf(TLinkedList* list, int value);
bool listGet(TLinkedList* list, int index, int* out);
void listFree(TLinkedList* list);
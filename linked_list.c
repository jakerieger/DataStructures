#include "linked_list.h"

#include <stddef.h>
#include <stdlib.h>

void listInit(TLinkedList* list) {
    list->head = NULL;
    list->count = 0;
}

bool listPush(TLinkedList* list, const int value) {
    TNode* node = (TNode*) malloc(sizeof(TNode));
    if (node == NULL) {
        return false;
    }

    node->value = value;
    node->next = list->head;
    list->head = node;
    list->count++;

    return true;
}

bool listPushBack(TLinkedList* list, const int value) {
    TNode* node = (TNode*) malloc(sizeof(TNode));
    if (node == NULL) {
        return false;
    }

    node->value = value;
    node->next = NULL;

    if (list->head == NULL) {
        list->head = node;
    } else {
        TNode* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
    }

    list->count++;
    return true;
}

bool listPop(TLinkedList* list, int* out) {
    if (list->head == NULL) {
        return false;
    }

    const int value = list->head->value;
    TNode* head = list->head;
    TNode* newHead = list->head->next;
    list->head = newHead;
    free(head);

    if (out != NULL)
        *out = value;
    list->count--;
    return true;
}

bool listPopBack(TLinkedList* list, int* out) {
    if (list->head == NULL) {
        return false;
    }

    TNode* current = list->head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    const int value = current->next->value;
    free(current->next);
    current->next = NULL;
    if (out != NULL)
        *out = value;
    list->count--;
    return true;
}

int listRemoveValue(TLinkedList* list, const int value) {
    if (list->head == NULL) {
        return 0;
    }

    int found = 0;
    if (list->head->value == value) {
        listPop(list, NULL);
        found++;
    }
    TNode* current = list->head;
    while (current->next != NULL) {
        if (current->next->value == value) {
            TNode* temp = current->next;
            current->next = current->next->next;
            free(temp);
            found++;
        }

        current = current->next;
    }

    list->count--;
    return found;
}

bool listRemoveIndex(TLinkedList* list, const int index) {
    if (list->head == NULL) {
        return false;
    }
    if (index >= list->count) {
        return false;
    }

    int i = 0;
    if (index == i) {
        listPop(list, NULL);
        return true;
    }
    TNode* current = list->head;
    while (current->next != NULL) {
        ++i;
        if (i == index) {
            TNode* temp = current->next;
            if (current->next->next != NULL)
                current->next = current->next->next;
            free(temp);
        }
        current = current->next;
    }

    list->count--;
    return true;
}

bool listContains(const TLinkedList* list, const int value) {
    if (list->head == NULL) {
        return false;
    }

    const TNode* current = list->head;
    while (current->next != NULL) {
        if (current->value == value) {
            return true;
        }
        current = current->next;
    }

    return false;
}

bool listGet(TLinkedList* list, const int index, int* out) {
    if (list->head == NULL) {
        return false;
    }
    if (index >= list->count) {
        return false;
    }

    int i = 0;
    if (index == i) {
        listPop(list, out);
        return true;
    }
    const TNode* current = list->head;
    while (current->next != NULL) {
        ++i;
        if (i == index) {
            *out = current->next->value;
            return true;
        }
        current = current->next;
    }

    return false;
}

void listFree(TLinkedList* list) {
    TNode* node = list->head;
    while (node != NULL) {
        TNode* cur = node;
        node = cur->next;
        free(cur);
    }
    list->head = NULL;
    list->count = 0;
}

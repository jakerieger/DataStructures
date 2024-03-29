#pragma once

#include <stdbool.h>

typedef struct Vector {
    int* values;
    int capacity;
    int size;
} TVector;

bool vecInit(TVector* vec);
void vecPushBack(TVector* vec, int value);
bool vecFrom(TVector* vec, int data[], int count);
bool vecAt(TVector* vec, int index, int* out);
bool vecRemove(TVector* vec, int index);
bool vecContains(TVector* vec, int value);
bool vecClear(TVector* vec);
bool vecEmpty(TVector* vec);
void vecFree(TVector* vec);
void vecPrint(TVector* vec);
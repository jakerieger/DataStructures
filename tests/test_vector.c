#include <stdio.h>
#include "../vector.h"

int main(int argc, char** argv) {
    TVector vec;
    vecInit(&vec);
    vecFree(&vec);
    printf("Vector Tests\n");
    return 0;
}
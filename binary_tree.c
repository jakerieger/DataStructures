#include "binary_tree.h"

#include <stddef.h>

void treeInit(TBinaryTree* tree) {
    tree->count = 0;
    tree->root = NULL;
}

void treeInsert(TBinaryTree* tree, int value) {}

void treeRemove(TBinaryTree* tree, int value) {}

bool treeContains(TBinaryTree* tree, int value) {
    if (tree->root == NULL)
        return false;

    return false;
}

void treeFree(TBinaryTree* tree) {}
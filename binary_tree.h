#pragma once

#include <stdbool.h>

typedef struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
} TTreeNode;

typedef struct BinaryTree {
    TTreeNode* root;
    int count;
} TBinaryTree;

void treeInit(TBinaryTree* tree);
void treeInsert(TBinaryTree* tree, int value);
void treeRemove(TBinaryTree* tree, int value);
bool treeContains(TBinaryTree* tree, int value);
void treeFree(TBinaryTree* tree);
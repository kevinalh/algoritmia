#pragma once

#include <stdlib.h>
#include "graph.h"

typedef TVertex* TElementBST;

typedef struct node {
    TElementBST val;
    struct node* left;
    struct node* right;
} TNode;

typedef struct bst {
    TElementBST* root;
} TBst;

void bstInitialize(TBst*);
void bstInsertNode(TBst*, TElementBST);
int bstCompare(TElementBST, )
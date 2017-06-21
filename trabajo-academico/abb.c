#include <stdlib.h>

#include "abb.h"

void bstInitialize(TBst* t) {
    t->root = NULL;
}

TElement bstInsertionPoint(TBst* t, TElementBST v) {
    TNode* node = t->root;
    TNode* aux = node;
    while(node != NULL) {
        if(bstCompare())
    }
    return aux;
}

void bstInsertNode(TBst* t, TElementBST v) {
    TNode* node = bstInsertionPoint(t, v);
}
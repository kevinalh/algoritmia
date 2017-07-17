#include <stdlib.h>

#include "abb.h"

void bstInitialize(BSTree* tree) {
    tree->root = NULL;
    return;
}

void bstInsert(BSTree* tree, BSTElement a) {
    BSTNode* node = malloc(sizeof(BSTNode));
    node->right = NULL;
    node->left = NULL;
    node->value = a;
    BSTNode* crawl = tree->root;
    if(crawl == NULL) {
        tree->root = node;
    } else {
        BSTNode* tmp = crawl;
        while(crawl != NULL) {
            tmp = crawl;
            if(a > crawl->value) crawl = crawl->right;
            else if (a < crawl->value) crawl = crawl->left;
            else {
                free(node);
                return;
            }
        }
        if(a > tmp->value) tmp->right = node;
        else tmp->left = node;
    }
    return;
}
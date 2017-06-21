#pragma once

#include <stdlib.h>
#include <string.h>

typedef char* TKey;
typedef int TValue;

typedef struct node {
    TKey* key;
    TValue value;
    struct node* next;
} TNode;

typedef struct list {
    TNode* begin;
    TNode* end;
    int nElements;
} TList;

typedef struct hash {
    int M;
    int N;
    TList* list;
} THash;

void listInitialization(TList*);
void listPrint(TList*);
void listInsert(TList*, TKey, TValue);

void hashInitialization(THash*, int M);
void hashPrint(THash*);
int hashFunction(TKey, int);
void hashInsert(THash*, TKey, TValue); 

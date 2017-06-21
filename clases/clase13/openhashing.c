#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "openhashing.h"

void listInitialize(TList* list) {
    list->begin = NULL;
    list->end = NULL;
    list->nElements = 0;
    return;
}

void listPrint(TList* list) {
    TNode* aux = list->begin;
    while(aux != NULL) {
        printf("(%s,%d)\t", aux->key, aux->value);
        aux = aux->next;
    }
    printf("\n");
    return;

}
void listInsert(TList* list, TKey key, TValue v) {
    TNode* aux = list->begin;
    if(aux == NULL) {
        /* La lista está vacía */
        TNode* node = malloc(sizeof(TNode));
        node->key = malloc(strlen(key)*sizeof(char));
        strcpy(node->key, key);
        node->value = v;
        list->begin = node;
        list->end = node;
        list->nElements++;
    } else {
        while(aux != NULL) {
            if(strcmp(aux->key, key) == 0) {
                aux->value = v;
                break;
            }
            aux = aux->next;
        }
        if(aux == NULL) {
            /* Llegó al final y no lo encontró */
            TNode* node = malloc(sizeof(TNode));
            node->key = malloc(strlen(key)*sizeof(char));
            strcpy(node->key, key);
            node->value = v;
            list->end->next = node;
            list->end = node;
            list->nElements++;
        }
    }
    return;
}

void hashInitialization(THash* hash, int M) {
    hash->M = M;
    hash->N = 0;
    hash->list = malloc(M*sizeof(TList));
    return;
}

void hashPrint(THash* hash) {
    int m = hash->M;
    int i;
    for(i = 0; i < m; ++i) {
        printf("%d\t->\t", i);
        listPrint(hash->list + i);
    }
    printf("\n");
    return;
}

int hashFunction(TKey key, int m) {
   int i, len, sum;
   len = strlen(key);
   sum = 0;
   for(i = 0; i < len; ++i) {
       sum += key[i] - 'A';
   }
   return sum % m;
}

void hashInsert(THash* hash, TKey key, TValue value) {
    int index = hashFunction(key, hash->M);
    listInsert(hash->list+index, key, value);
    return;
}

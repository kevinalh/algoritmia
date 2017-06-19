#ifndef LIST_H
#define LIST_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
    
    typedef struct Info {
        int pos;
        int val;
    } TInfo;
    
    typedef struct Node {
        TInfo info;
        struct Node* next;
    } TNode;
    
    typedef struct List {
        struct Node* first;
        struct Node* last;
    } TList;
    
    void init_list(TList* list) {
        list->first = NULL;
        list->last = NULL;
        return;
    }
    
    void kill_list(TList* list) {
        TNode* aux = list->first;
        while(aux != NULL) {
            list->first = aux->next;
            free(aux);
            aux=list->first;
        }
        return;
    }
    
    int is_empty(TList* list) {
        if(list->first==NULL && list->last==NULL) {
            return 1;
        }
        return 0;
    }
    
    void insert_list_end(TList* list, TInfo x) {
        TNode* node = malloc(sizeof(TNode));
        node->info = x;
        node->next = NULL;
        if(is_empty(list)) {
            list->first=node;
            list->last=node;
        } else {
            list->last->next=node;
            list->last=node;
        }
        return;
    }

    void print_list(TList* list) {
        TNode* actual = list->first;
        while(actual!=NULL) {
            printf("%d %d ", actual->info.pos, actual->info.val);
            actual = actual->next;
        }
        printf("\n");
        return;
    }

#ifdef __cplusplus
}
#endif

#endif /* LIST_H */


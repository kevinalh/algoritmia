#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "list.h"

#define SMAX 500

void pop_zeroes_list(TList* list) {
    TNode* aux = list->first;
    while(aux != NULL && aux->info == 0) {
        list->first=aux->next;
        free(aux);
        aux=list->first;
        if(aux == NULL) {
            insert_list_first(list, 0);
            return;
        }
    }
    return;
}

void carry(TNode* node) {
    if(node == NULL) return;
    if(node->info > 0) {
        node->info = node->info - 1;
    }
    else {
        node->info = 9;
        carry(node->next);
    }
    return;
}

void list_diff(TList* list1, TList* list2, TList* diff) {
    /* Asumimos que list1 es mayor que list2,
     y que diff esta vacio*/
    TList a, b;
    int resta = 0;
    init_list(&a);
    init_list(&b);
    invertir(list1, &a);
    invertir(list2, &b);
    TNode* node1 = a.first;
    TNode* node2 = b.first;
    while(node1 != NULL) {
        if(node2 != NULL) {
            resta = node1->info - node2->info; 
            if(resta < 0) {
                resta += 10;
                carry(node1->next);
            }
            node2 = node2->next;
        }
        else {
            resta = node1->info;
        }
        insert_list_first(diff, resta);
        node1 = node1->next;
    }
    pop_zeroes_list(diff);
    return;
}

int list_greater(TList* list1, TList* list2) {
    /* Devuelve 1 si list1 >= list2, 0 c.c. */
    TNode* node1 = list1->first;
    TNode* node2 = list2->first;
    while(node1 != NULL && node2 != NULL) {
        if(node1->info < node2->info) {
            return 0;
        }
        if(node1->info > node2->info) {
            return 1;
        }
        node1 = node1->next;
        node2 = node2->next;
    }
    return 1;
}

int main() {
    char s[SMAX];
    int i, len1, len2, digit;
    TList n1, n2, diff;
    init_list(&n1);
    init_list(&n2);
    init_list(&diff);
    fgets(s, SMAX-1, stdin);
    len1 = strlen(s)-1;
    for(i = 0; i < len1; ++i) {
        digit = (int) (s[i]-'0');
        insert_list_end(&n1, digit);
    }
    fgets(s, SMAX-1, stdin);
    len2 = strlen(s)-1;
    for(i = 0; i < len2; ++i) {
        digit = (int) (s[i]-'0');
        insert_list_end(&n2, digit);
    }
    TList aux;
    if(len1 == len2) {
        if(!list_greater(&n1, &n2)) {
            aux = n1;
            n1 = n2;
            n2 = aux;
        }
    }
    else if(len1 < len2) {
        aux = n1;
        n1 = n2;
        n2 = aux;
    }
    list_diff(&n1, &n2, &diff);
    print_list(&diff);
    kill_list(&n1);
    kill_list(&n2);
    kill_list(&diff);
    return(EXIT_SUCCESS);
}


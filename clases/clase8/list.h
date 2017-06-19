#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* s;
} node;

typedef struct list {
    struct node* ini;
    struct node* fin;
    int sz;
} list;

int estavacia(list* lista) {
    return lista->sz == 0;
}

void push(list* lista, int a) {
    node* nodo = malloc(sizeof(nodo));
    if(nodo) {
        nodo->val = a;
        nodo->s = NULL;
        if(estavacia(lista)) {
            lista->ini = nodo;
        }
        else {
            lista->fin->s = nodo;
        }
        lista->fin = nodo;
        lista->sz++;
    }
    return;
}

void push_behind(list* lista, int a) {
    node* nodo = malloc(sizeof(nodo));
    if(nodo) {
        nodo->val = a;
        nodo->s = lista->ini;
        if(estavacia(lista)) {
            lista->fin = nodo;
        }
        lista->ini = nodo;
        lista->sz++;
    }
    return;
}

void imprimir(list* lista) {
    node* ptr = lista->ini;
    while(ptr != NULL) {
        printf("%d ", ptr->val);
        ptr = ptr->s;
    }
    printf("\n");
    return;
}

void crear(list* lista) {
    lista->ini = NULL;
    lista->fin = NULL;
    lista->sz = 0;
}
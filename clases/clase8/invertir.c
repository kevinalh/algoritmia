#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
            (lista->fin)->s = nodo;
        }
        lista->fin = nodo;
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

void invertir(list* lista) {
    node* ptr = lista->fin;

}

int main() {
    int i, n, tmp;
    scanf("%d", &n);
    list lista;
    crear(&lista);
    for(i = 0; i < n; ++i) {
        scanf("%d", &tmp);
        push(&lista, tmp);
    }
    imprimir(&lista);
    
    return 0;
}

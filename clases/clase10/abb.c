#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abb.h"

void init_abb(TABB* t) {
    t->raiz = NULL;
    return;
}

void abb_insert_node(TNode* sub, TNode* e) {
    if(sub->info < e->info) {
        if(sub->der == NULL) {
            sub->der = e;
        } else {
            abb_insert_node(sub->der, e);
        }
    } else {
        if(sub->izq == NULL) {
            sub->izq = e;
        } else {
            abb_insert_node(sub->izq, e);
        }
    }
}

void insert_abb(TABB* t, TElement e) {
    TNode* n = malloc(sizeof(TNode));
    if(n) {
        n->info = e;
        n->izq = NULL;
        n->der = NULL;
        if(t->raiz == NULL) {
            t->raiz = n;
        } else {
            abb_insert_node(t->raiz, n);
        }
    }
    return;
}

void abb_preorden(TNode* t) {
    if(t != NULL) {
        printf("%d ", t->info);
        abb_preorden(t->izq);
        abb_preorden(t->der);
    }
    return;
}

void abb_enorden(TNode* t) {
    if(t != NULL) {
        abb_enorden(t->izq);
        printf("%d ", t->info);
        abb_enorden(t->der);
    }
    return;
}

void abb_postorden(TNode* t) {
    if(t != NULL) {
        abb_postorden(t->izq);
        abb_postorden(t->der);
        printf("%d ", t->info);
    }
    return;
}

void abb_imprimir(TABB* t, int mode) {
    switch(mode) {
        case 1: abb_preorden(t->raiz); break;
        case 2: abb_enorden(t->raiz); break;
        case 3: abb_postorden(t->raiz); break;
        default: abb_preorden(t->raiz); break;
    }
    printf("\n");
    return;
}

int abb_contar_nodos(TNode* nodo) {
    if(nodo == NULL) {
        return 0;
    }
    return 1 + abb_contar_nodos(nodo->izq) + abb_contar_nodos(nodo->der);
}

int abb_contar(TABB* t) {
    return abb_contar_nodos(t->raiz);
}

int esABB(TNode* n) {
    if(n != NULL) {
        if(n->izq != NULL) {
            if(n->izq->info > n->info) {
                return 0;
            }
        }
        if(n->der != NULL) {
            if(n->der->info < n->info) {
                return 0;
            }
        }
        return esABB(n->der) && esABB(n->izq); 
    }
    return 1;
}

int main() {
    TABB t;
    init_abb(&t);
    int i, n, m;
    scanf("%d", &n);
    for(i = 0; i < n; ++i) {
        scanf("%d", &m);
        insert_abb(&t, m);
    }
    abb_imprimir(&t, 1);
    abb_imprimir(&t, 2);
    abb_imprimir(&t, 3);
    printf("El numero de nodos es %d.\n", abb_contar(&t));
    return 0;
}

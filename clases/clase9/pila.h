#include <stdlib.h>

typedef int TElement;

typedef struct nodo {
    TElement info;
    struct nodo *s;
} TNodo;

typedef struct pila {
    TNodo *top;
} TPila;

void pila_crear(TPila*);
void pila_apilar(TPila*, TElement);
TElement pila_desapilar(TPila*);
TElement pila_tope(TPila*);
int pila_vacia(TPila*);
void pila_finalizar(TPila*);

void pila_crear(TPila* p) {
    return;
}

int pila_vacia(TPila* p) {
    return p->top == NULL;
}

void pila_apilar(TPila* p, TElement n) {
    TNodo *a = malloc(sizeof(TNodo));
    if(a) {
        a->info = n;
        if(pila_vacia(p)) {
            a->s = NULL;
            p->top = a;
        }
        else {
            a->s = p->top;
            p->top = a;
        }
    }
    return;
}

TElement pila_desapilar(TPila* p) {
    TElement info = -1;
    if(!pila_vacia(p)) {
        info = p->top->info;
        TNodo *aux = p->top;
        p->top = p->top->s;
        free(aux);
    }
    return info;
}

TElement pila_tope(TPila *p) {
    return p->top->info;
}

void pila_finalizar(TPila* p) {
    while(!pila_vacia(p)) {
        pila_desapilar(p);
    }
    return;
}

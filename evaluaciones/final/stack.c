#include <stdio.h>
#include <stdlib.h>
#include "Pila.h"

void Pila_init(TPila *P){
    P->top = NULL;
}
void Pila_push(TPila *P, TElemento nuevoElem){
    TNodo *ptr_nuevoElem;
    
    ptr_nuevoElem = malloc(sizeof(TNodo));
    
    if (ptr_nuevoElem){
        ptr_nuevoElem->info = nuevoElem;
        ptr_nuevoElem->sig = P->top;
        P->top = ptr_nuevoElem;
    }
}

TElemento Pila_pop(TPila *P){
    TElemento top_info; TNodo *ptr_top;
    if (!Pila_isEmpty(P)){
        ptr_top = P->top;
        top_info = ptr_top->info;
        P->top = P->top->sig;
        free(ptr_top);
        return top_info;
    }
    return -1;
}

int Pila_isEmpty(TPila *P){
    return (P->top == NULL);
}

void Pila_finalize(TPila *P){
    while (!Pila_isEmpty(P))
        Pila_pop(P);
}       

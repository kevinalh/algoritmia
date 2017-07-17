#include <stdlib.h>
#include <stdio.h>
#include "Lista.h"

void Lista_Crear(TLista *L){
    L->inicio = NULL;
    L->fin = NULL;
    L->numElem = 0;
}

int Lista_EstaVacia(TLista L){
    return L.numElem == 0;
}

void Lista_Insertar(TLista *L, TElemento e){
    TNodo *ptrNuevo = malloc(sizeof(TNodo));
    if (ptrNuevo != NULL){
        ptrNuevo->elem = e;
        ptrNuevo->sig = NULL;
        // Insertar al final de la lista
        if (Lista_EstaVacia(*L))
            L->inicio = ptrNuevo;
        else
            L->fin->sig = ptrNuevo;
        L->fin = ptrNuevo;
        (L->numElem)++;
    }
}

void Lista_Eliminar(TLista *L, TElemento e){   
    if (!Lista_EstaVacia(*L)){
        TNodo *ptrActual = L->inicio;
        TNodo *ptrAnt = NULL;
        while (ptrActual != NULL ){
            if (ptrActual->elem == e)
                break;
            ptrAnt = ptrActual;
            ptrActual = ptrActual->sig;
        }
        if (ptrActual != NULL){// Lo encontró
            // Es el primer elemento de la lista
            if (ptrAnt == NULL){ // ptrActual == L->inicio
                L->inicio = L->inicio->sig;
            }
            // Es el último elemento
            if (ptrActual->sig == NULL){ // ptrActual == L->fin
                if (ptrAnt != NULL) ptrAnt->sig = NULL;
                L->fin = ptrAnt;
            }else{
            // Es un elemento del medio
                if (ptrAnt != NULL) ptrAnt->sig = ptrActual->sig;
            }
            free(ptrActual);
            (L->numElem)--;
        }
    }
}

int Lista_Tamanho(TLista L){
    return L.numElem;
}

int Lista_EstaEnLista(TLista L, TElemento e){
    TNodo *ptrRec = L.inicio;
    while (ptrRec!=NULL && ptrRec!=e)
        ptrRec = ptrRec->sig;
    return ptrRec!=NULL;
}

void Lista_Imprimir(TLista L){
    TNodo *ptrRec = L.inicio;
    while(ptrRec != NULL){
        printf("%d ", ptrRec->elem);
        ptrRec = ptrRec->sig;
    }
    printf("\n");
}

void Lista_Finalizar(TLista *L){
    
}
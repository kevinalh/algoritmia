/* 
 * File:   ListaST.h
 * Author: Fernando Alva Manchego
 *
 */

#ifndef LISTAST_H
#define	LISTAST_H

typedef int TElemento;

typedef struct nodo TNodo;

typedef struct nodo{
    TElemento elem;
    struct nodo *sig;
}TNodo;

typedef struct lista{
    TNodo *inicio;
    TNodo *fin;
    int numElem;
}TLista;

void Lista_Crear(TLista *);
void Lista_Finalizar(TLista *);
int Lista_EstaVacia(TLista);
void Lista_Insertar(TLista *, TElemento);
void Lista_Eliminar(TLista *, TElemento);
int Lista_Tamanho(TLista);
int Lista_EstaEnLista(TLista, TElemento);
void Lista_Imprimir(TLista);


#endif	/* LISTAST_H */


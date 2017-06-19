#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "graph.h"

void graphInitialize(TGraph* g) {
    g->first = NULL;
    g->last = NULL;
    g->size = 0;
    return;
}

/**
* Crea una arista entre los dos elementos (o aumenta el peso
* si ya existe). De no existir alguno de los vértices, los
* crea.
*/
void graphInsertPair(TGraph* g, TElement s, TElement t) {
    TVertex* v1 = graphInsertVertex(g, s);
    TVertex* v2 = graphInsertVertex(g, t);
    v1->deg++;
    v2->deg++;
    return;
}

void graphInsertEdge(TVertex* v1, TElement v2) {
    
}

/**
* Devuelve un puntero al vértice que contenga al elemento
* buscado, o NULL si no existe.
*/
TVertex* graphVertexSearch(TGraph* g, TElement s) {
    TVertex* v = g->root;
    int c;
    while(v != NULL) {
        c = compare(v->val, s);
        if(c == 0) return v;
        if(c < 0) v = v->left;
        else v = v->right;
    }
    return NULL;
}

/**
* Devuelve el nodo del árbol binario donde se insertaría el
* elemento, en caso de no existir. Caso contrario, devuelve
* el vértice cuyo valor es el indicado.
* Devuelve NULL si el grafo está vacío.
* Se usa búsqueda binaria, evitando la complejidad lineal.
*/
TVertex* graphVertexPointOfInsertion(TGraph* g, TElement s) {
    TVertex* v = g->root;
    TVertex* aux = v;
    int c;
    while(v != NULL) {
        aux = v;
        c = compare(v->val, s);
        if(c == 0) return v;
        if(c < 0) v = v->left;
        else v = v->right;
    }
    return aux;
}

/**
* Evalúa si el grafo está vacío.
*/
int graphIsEmpty(TGraph* g) {
    return g->root != NULL;
}

/**
* Inserta un elemento al grafo, respetando la caracterización
* del árbol binario.
* Devuelve el vértice que acaba de ser insertado.
* Si el vértice ya existe, se devuelve un puntero a este.
* Termina con la ejecución del programa si ocurre un error al
* reservar memoria.
*/
TVertex* graphInsertVertex(TGraph* g, TElement s) {
    TVertex* insertion = graphVertexPointOfInsertion(g, s);
    /* Si se encontró el vértice, no se debe agregar. */
    if(insertion != NULL && compare(insertion->val, s) == 0) {
        return insertion;
    }
    TVertex* v = malloc(sizeof(TVertex));
    if(v) {
        g->size++;
        v->val = s;
        v->first = NULL;
        v->last = NULL;
        v->deg = 0;
        if(graphIsEmpty(g)) {
            g->root = v;
        }
        else {
            if(compare(insertion->val, s) < 0) {
                insertion->left = v;
            }
            else insertion->right = v;
        }
        return v;
    }
    else {
        reportError("Memory");
    }
    return NULL;
}

/**
* Inserta una arista al grafo
*/
TEdge* graphInsertEdge(TGraph* g, TElement t, TElement s) {

}

/**
* Función de comparación.
* Con fines de abstracción de código.
*/
int compare(TElement x, TElement y) {
    return strcmp(x, y);
}

/**
* Función que reporta errores que pueden suceder durante
* la ejecución del programa, y termina con la ejecución.
*/
void reportError(char* s) {
    fprintf(stderr, "%s error.\n", s);
    exit(EXIT_FAILURE);
}
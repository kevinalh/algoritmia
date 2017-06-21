#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "graph.h"

/**
* Inicializa el grafo, reservando memoria para una cantidad
* dada de vértices.
*/
void graphInitialize(TGraph* g, int size) {
    g->size = 0;
    g->maxsize = size-1;
    g->nodes = malloc(size*sizeof(TVertex));
	if (g->nodes == NULL) reportError("Memory");
    g->tree.root = NULL;
	g->tree.depth = 0;
    return;
}

/**
* Revisa si se necesita más memoria para almacenar el grafo.
* De ser así, almacena más (Experimental).
*/
void graphCheckMemory(TGraph* g) {
    int limit = g->maxsize;
    if(g->size >= limit - 1) {
        int newlimit = limit*2;
        g->nodes = realloc(g->nodes, newlimit);
        if(g->nodes == NULL) reportError("Memory");
        g->maxsize = newlimit;
    }
    return;
}

/**
* Inserta una arista al grafo no dirigido.
*/
void graphInsertEdge(TGraph* g, TElement s, TElement t) {
    int a = graphInsertVertex(g, s);
    int b = graphInsertVertex(g, t);
    TEdge* e = graphSearchEdgeAroundVertex(g, a, b);
    /* Si la arista no está en un lado, asumimos que no hay
    desincronización y no está en ambos vértices. */
    if(e == NULL) {
        /* Colocamos la arista hacia b en a */
        TEdge* new_edge = malloc(sizeof(TEdge));
        if(new_edge == NULL) reportError("Memory");
        graphInitializeEdge(new_edge, b);
        graphInsertEdgeToVertex(g, a, new_edge);
        /* Y luego la arista hacia a en b */
        new_edge = malloc(sizeof(TEdge));
        if(new_edge == NULL) reportError("Memory");
        graphInitializeEdge(new_edge, a);
        graphInsertEdgeToVertex(g, b, new_edge);
    } else {
        /* Si la arista ya está, tenemos que sumar 1 al peso
        en ambos lados. */
        e->weight++;
        TEdge* d = graphSearchEdgeAroundVertex(g, b, a);
        d->weight++;
    }
    /* Aumentar una arista siempre aumentará el grado por 1 */
    g->nodes[a].degree++;
    g->nodes[b].degree++;
    return;
}

/**
* Busca arista en la lista del vértice. Da un puntero a la arista
* buscada, o NULL si no se encuentra.
*/
TEdge* graphSearchEdgeAroundVertex(TGraph* g, int vindex, int a) {
    TVertex* v = graphVertexPointer(g, vindex);
    TEdge* e = v->first;
    while(e != NULL) {
        if(e->index == a) return e;
        e = e->next;
    }
    return e;
}

/**
* Inicializa una arista.
*/
void graphInitializeEdge(TEdge* e, int i) {
    e->index = i;
    e->weight = 1;
    e->next = NULL;
    return;
}

/**
* Coloca una arista a un vértice, dado el índice del vértice
* a donde apunta.
* No verifica si la arista ya existe.
*/
void graphInsertEdgeToVertex(TGraph* g, int vindex, TEdge* e) {
    TVertex* v = graphVertexPointer(g, vindex);
    if(v->first == NULL) {
        v->first = e;
        v->last = e;
    }
    else {
        v->last->next = e;
        v->last = e;
    }
    return;
}

/**
* Inserta un vértice al grafo, y devuelve el índice donde se encuentra.
* Funciona igual si ya estaba.
*/
int graphInsertVertex(TGraph* g, TElement s) {
    int a = graphVertexIndex(g, s);
    if(a == -1) {
        int n = g->size;
		TVertex* v = &(g->nodes[n]);
        /* Inicializamos el vértice (que ya está reservado) */
        graphInitializeVertex(v, s);
        g->size++;
        /* Revisamos que no se tenga desborde de memoria */
        graphCheckMemory(g);
        graphPutVertexInTree(g, n);
        return n;
    }
    return a;
}

/**
* Coloca el vértice en el árbol binario.
* Si el vértice ya está en el árbol, genera un error fatal que cierra el
* programa.
*/
void graphPutVertexInTree(TGraph* g, int pos) {
    /* Creamos el nodo para el árbol binario */
    TBstNode* node = malloc(sizeof(TBstNode));
	if (node == NULL) reportError("Memory");
    char* s = g->nodes[pos].value;
    if(node == NULL) reportError("Memory");
    node->index = pos;
    node->left = NULL;
    node->right = NULL;
    TBstNode* curr = g->tree.root;
    /* Si el árbol está vacío, colocamos el nodo en la raíz */
    if(curr == NULL) {
		node->depth = 1;
        g->tree.root = node;
        return;
    }
    /* Caso contrario, buscamos el punto de inserción */
    int c, i;
    while(curr != NULL) {
        i = curr->index;
        c = cmp(g->nodes[i].value, s);
        if(c==0) reportError("The vertex is already in the tree. Logic");
        else if(c<0) {
            if(curr->left == NULL) {
				node->depth = curr->depth + 1;
				if (node->depth > g->tree.depth) {
					g->tree.depth = node->depth;
				}
                curr->left = node;
                return;
            } else curr = curr->left;
        }
        else {
            if(curr->right == NULL) {
				node->depth = curr->depth + 1;
				if (node->depth > g->tree.depth) {
					g->tree.depth = node->depth;
				}
                curr->right = node;
                return;
            } else curr = curr->right;
        }
    }
    /* Tiene que tenerse la inserción en este punto */
    reportError("Logic");
    return;
}

/**
* Inicializa un vértice de acuerdo al valor dado.
*/
void graphInitializeVertex(TVertex* v, TElement s) {
    v->value = s;
    v->first = NULL;
    v->last = NULL;
    v->degree = 0;
    return;
}

/**
* Consigue el índice del vértice que contiene al valor dado.
* De no encontrarse, se devuelve -1.
* Implementación: Búsqueda binaria sobre el ABB.
*/
int graphVertexIndex(TGraph* g, TElement s) {
    TBstNode* node = g->tree.root;
    int c, i;
    while(node != NULL) {
        i = node->index;
        c = cmp(g->nodes[i].value, s);
        if(c==0) return i;
        else if(c<0) node = node->left;
        else node = node->right;
    }
    return -1;
}

/**
* Si el vértice existe en el grafo, se devuelve 1. Caso contrario, 0.
*/
int graphVertexExists(TGraph* g, TElement s) {
    if(graphVertexIndex(g, s) == -1) return 0;
    return 1;
}

/**
* Devuelve un puntero al vértice dado su índice, o NULL si no
* está.
*/
TVertex* graphVertexPointer(TGraph* g, int vindex) {
    if(vindex >= g->size) return NULL;
    return &(g->nodes[vindex]);
}

/**
* Función de comparación.
* Devuelve 0 si x = y, un entero negativo si x < y, y un
* entero positivo si x > y.
* Con fines de abstracción de código.
*/
int cmp(TElement x, TElement y) {
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

/**
* Imprime todo el grafo.
*/
void graphPrint(TGraph* g, FILE* fp) {
    int i;
    fprintf(fp, "Size: %d\n", g->size);
    fprintf(fp, "Maximum size: %d\n", g->maxsize);
	fprintf(fp, "Binary Search Tree depth: %d\n", g->tree.depth);
	TVertex* v;
	for(i = 0; i < g->size; ++i) {
		v = malloc(sizeof(TVertex));
		graphVertexPrint(g, i, fp);
		v = malloc(sizeof(TVertex));
	}
    return;
}

/**
* Imprime la información de un vértice dado su índice.
*/
void graphVertexPrint(TGraph* g, int vindex, FILE* fp) {
    TVertex* v = graphVertexPointer(g, vindex);
    if(v == NULL) {
        fprintf(fp, "Vertex %d doesn't exist.\n", vindex);
        return;
    }
    fprintf(fp, "%d %s -> ", vindex, v->value);
    TEdge* e = v->first;
    while(e != NULL) {
        fprintf(fp, "%d (%d) ", e->index, e->weight);
        e = e->next;
    }
    fprintf(fp, "\n");
    return;
}

/**
* Libera toda la memoria.
*/
void graphCleanAll(TGraph* g) {
    /* Primero liberamos el ABB */
    /* TODO */
    /* Ahora liberamos la memoria de vértices y aristas */
    int i;
    TEdge* e;
    TVertex* v;
    for(i = 0; i < g->size; ++i) {
        v = graphVertexPointer(g, i);
        e = v->first;
    }
    return;
}
#pragma once

#include <stdlib.h>

typedef char* TElement;

typedef struct edge {
    TElement val;
    int w;
    struct edge* next;
} TEdge;

typedef struct vertex {
    TElement val;
    TEdge* first;
    TEdge* last;
    int deg;
    struct vertex* next;
} TVertex;

typedef struct graph {
    int size;
    TVertex* first;
    TVertex* last;
} TGraph;

void reportError(char*);
int compare(TElement, TElement);
void graphInitialize(TGraph*);
TVertex* graphInsertVertex(TGraph*, TElement);
TEdge* graphInsertEdge(TVertex*, TElement);
TVertex* graphVertexSearch(TGraph*, TElement);
TEdge* graphEdgePointOfInsertion(TGraph*, TElement, TElement);
void graphInsertPair(TGraph*, TElement, TElement);
int graphIsEmpty(TGraph*);
#pragma once

#include <stdlib.h>
#include <stdio.h>

typedef char* TElement;

typedef struct edge {
    int index;
    int weight;
    struct edge* next;
} TEdge;

typedef struct vertex {
    TElement value;
    TEdge* first;
    TEdge* last;
    int degree;
} TVertex;

typedef struct binarySearchTreeNode {
	int index;
	int depth;
    struct binarySearchTreeNode* left;
    struct binarySearchTreeNode* right;
} TBstNode;

typedef struct binarySearchTree {
	int depth;
    TBstNode* root;
} TBst;

typedef struct graph {
    int maxsize;
    int size;
    TVertex* nodes;
    TBst tree;
} TGraph;

/* Funciones utilitarias */
void reportError(char*);
int cmp(TElement, TElement);
void graphPrint(TGraph*, FILE*);
void graphVertexPrint(TGraph*, int, FILE*);
void graphCleanAll(TGraph*);

/* Funciones que trabajan con el grafo */
void graphInitialize(TGraph*, int size);
int graphIsEmpty(TGraph*);
void graphCheckMemory(TGraph*);

/* Funciones que trabajan con los vértices */
int graphVertexIndex(TGraph*, TElement);
int graphVertexExists(TGraph*, TElement);
int graphInsertVertex(TGraph*, TElement);
void graphInitializeVertex(TVertex*, TElement);
void graphPutVertexInTree(TGraph*, int);
TVertex* graphVertexPointer(TGraph*, int);

/* Funciones para las aristas */
void graphInsertEdge(TGraph*, TElement, TElement);
void graphInsertEdgeToVertex(TGraph*, int, TEdge*);
TEdge* graphSearchEdgeAroundVertex(TGraph*, int, int);
void graphInitializeEdge(TEdge*, int);
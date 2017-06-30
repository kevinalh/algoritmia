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
	double pagerank;
	double closeness;
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
	int nEdges;
	TVertex* nodes;
	TBst tree;
} TGraph;

/* Funciones utilitarias */
void reportError(char* errorMessage);
int cmp(TElement x, TElement y);
void graphPrint(TGraph* g, FILE* fp);
void graphVertexPrint(TGraph* g, int vindex, FILE* fp);
void graphCleanAll(TGraph* g);
char* graphStringFromVertex(TGraph* g, int vindex);
void graphPrintExtra(TGraph* g, FILE* fp);
void graphCleanTree(TBstNode* node);

/* Funciones que trabajan con el grafo */
void graphInitialize(TGraph* g, int size);

/* Funciones que trabajan con los vértices */
int graphVertexIndex(TGraph* g, TElement s);
int graphVertexExists(TGraph* g, TElement s);
int graphInsertVertex(TGraph* g, TElement s);
void graphInitializeVertex(TVertex* v, TElement s);
void graphPutVertexInTree(TGraph* g, int pos);
TVertex* graphVertexPointer(TGraph* g, int vindex);

/* Funciones para las aristas */
void graphInsertEdge(TGraph* g, TElement s, TElement t);
void graphInsertEdgeToVertex(TGraph* g, int vindex, TEdge* e);
TEdge* graphSearchEdgeAroundVertex(TGraph* g, int vindex, int a);
void graphInitializeEdge(TEdge* e, int vindex);

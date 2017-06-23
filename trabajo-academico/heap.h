#pragma once

typedef int THElement;

typedef struct heap {
	THElement* array; /* Los índices de los vértices del grafo */
	int* table; /* Diccionario que toma el índice de un vértice
				(correspondiente al índice del arreglo) y devuelve
				la ubicación en el array anterior. */
	int size; /* Cantidad de elementos en el heap */
} THeap;

int heapParent(int index);
void heapInitialize(THeap* h, int size);
void heapInsert(THeap* h, double* dist, THElement value);
void heapInsertFast(THeap* h, THElement value);
void heapMinHeapify(THeap* h, double* dist, int value);
int heapIsEmpty(THeap* h);
int heapIndexVertex(THeap* h, int vindex);
THElement heapPopMinimum(THeap* h, double* dist);
void heapClean(THeap* h);
void heapDecreaseKey(THeap* h, double* dist, int vindex);
int heapIndexVertex(THeap* h, int vindex);
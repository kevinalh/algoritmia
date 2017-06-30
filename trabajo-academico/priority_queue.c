/*! \file */
#include <stdio.h>
#include <stdlib.h>

#include "priority_queue.h"

/**
* Compara dos elementos del priority queue.
*/
int pqCmp(TPair x, TPair y) {
	if (x.fst < y.fst) return 1;
	if (x.fst == y.fst) {
		if (x.snd < y.snd) return 1;
		if (x.snd == y.snd) return 0;
		if (x.snd > y.snd) return -1;
	}
	return -1;
}

/**
* Inserta un nodo a la cola de prioridad.
*/
void pqInsert(HeapNode nodo, HeapNode* heap, int size) {
	int idx = size + 1;
	HeapNode tmp;
	heap[idx] = nodo;
	while (pqCmp(heap[idx], heap[idx / 2]) == 1 && idx > 1) {
		tmp = heap[idx];
		heap[idx] = heap[idx / 2];
		heap[idx / 2] = tmp;
		idx /= 2;
	}
	return;
}

/**
* Regresa el heap a la condición que debe cumplir (heap condition).
*/
void pqRestore(HeapNode* heap, int size, int idx) {
	int l = 2 * idx;
	int r = 2 * idx + 1;
	int smallest = idx;
	HeapNode tmp;
	if (l <= size && (pqCmp(heap[l], heap[smallest]) == 1)) smallest = l;
	if (r <= size && (pqCmp(heap[r], heap[smallest]) == 1)) smallest = r;
	if (smallest != idx) {
		tmp = heap[idx];
		heap[idx] = heap[smallest];
		heap[smallest] = tmp;
		pqRestore(heap, size, smallest);
	}
}

/**
* Saca la raíz del heap, y lo devuelve.
*/
HeapNode pqRemoveRoot(HeapNode* heap, int size) {
	HeapNode front = heap[1];
	heap[1] = heap[size];
	pqRestore(heap, size - 1, 1);
	return front;
}

/**
* Reserva memoria para el heap.
*/
void pqInitialize(TPriorityQueue* pq, int sz) {
	pq->size = 0;
	pq->heap = malloc(sizeof(HeapNode)*(sz + 1));
	return;
}

/**
* Coloca un elemento al heap.
*/
void pqPush(TPriorityQueue* pq, HeapNode node) {
	pqInsert(node, pq->heap, pq->size);
	++pq->size;
	return;
}

/**
* Saca el elemento con más prioridad de la cola, y lo devuelve.
*/
HeapNode pqTop(TPriorityQueue *pq) {
	HeapNode front = pqRemoveRoot(pq->heap, pq->size);
	--pq->size;
	return front;
}

/**
* Verifica si la cola de prioridad está vacía.
*/
int pqEmpty(TPriorityQueue *pq) {
	if (pq->size == 0) return 1;
	return 0;
}

/**
* Limpia la memoria usada para la cola de prioridad.
*/
void pqClean(TPriorityQueue* pq) {
	while (!pqEmpty(pq)) {
		pqTop(pq);
	}
	free(pq->heap);
	return;
}
#include <stdio.h>
#include <stdlib.h>

#include "priority_queue.h"

int pqCmp(TPair x, TPair y) {
	if (x.fst < y.fst) return 1;
	if (x.fst == y.fst) {
		if (x.snd < y.snd) return 1;
		if (x.snd == y.snd) return 0;
		if (x.snd > y.snd) return -1;
	}
	return -1;
}

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

void pqRestore(HeapNode* heap, int size, int idx) {
	int l = 2 * idx;
	int r = 2 * idx + 1;
	int largest = idx;
	HeapNode tmp;
	if (l <= size && (pqCmp(heap[l], heap[largest]) == 1)) largest = l;
	if (r <= size && (pqCmp(heap[r], heap[largest]) == 1)) largest = r;
	if (largest != idx) {
		tmp = heap[idx];
		heap[idx] = heap[largest];
		heap[largest] = tmp;
		pqRestore(heap, size, largest);
	}
}

HeapNode pqRemoveRoot(HeapNode* heap, int size) {
	HeapNode front = heap[1];
	heap[1] = heap[size];
	pqRestore(heap, size - 1, 1);
	return front;
}

void pqInitialize(TPriorityQueue* pq, int sz) {
	pq->size = 0;
	pq->heap = malloc(sizeof(HeapNode)*(sz + 1));
	return;
}

void pqPush(TPriorityQueue* pq, HeapNode node) {
	pqInsert(node, pq->heap, pq->size);
	++pq->size;
	return;
}

HeapNode pqTop(TPriorityQueue *pq) {
	HeapNode front = pqRemoveRoot(pq->heap, pq->size);
	--pq->size;
	return front;
}

int pqEmpty(TPriorityQueue *pq) {
	if (pq->size == 0) return 1;
	return 0;
}

void pqClean(TPriorityQueue* pq) {
	while (!pqEmpty(pq)) {
		pqTop(pq);
	}
	free(pq->heap);
	return;
}
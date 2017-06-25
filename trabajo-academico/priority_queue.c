#include <stdio.h>
#include <stdlib.h>

#include "priority_queue.h"

int pqCmp(TPair x, TPair y){
	if(x.fst < y.fst) return 1;
	if(x.fst == y.fst){
		if(x.snd < y.snd) return 1;
		if(x.snd == y.snd) return 0;
		if(x.snd > y.snd) return -1;
	}
	return -1;
}

void pqInsert(HeapNode nodo, HeapNode* heap, int size){
    int idx = size + 1;
    HeapNode tmp;
    heap[idx] = nodo;
	while(pqCmp(heap[idx], heap[idx/2]) == 1 && idx > 1) {	
    	tmp = heap[idx];
   		heap[idx] = heap[idx/2];
    	heap[idx/2] = tmp;
    	idx /= 2;
    }
	return;
}

void pqRestore(HeapNode* heap, int size, int idx) {
	int idxtmp;
	HeapNode tmp; 
	while(1) {
		idxtmp = idx * 2;
		if(idxtmp > size) break;
		if(idxtmp < size) {
			if(pqCmp(heap[idxtmp], heap[idxtmp + 1]) == 1) {
				++idxtmp;
			}
		}
		if(pqCmp(heap[idxtmp],heap[idx]) == 1) {
			tmp = heap[idx]; 
			heap[idxtmp] = heap[idx]; 
			heap[idx] = tmp; 
			idx = idxtmp;
		}
		else break;
	}
	return;
}

HeapNode pqRemoveRoot(HeapNode* heap, int size) {
	HeapNode front = heap[1]; 
	heap[1] = heap[size];
	pqRestore(heap, size - 1, 1);
	return front;
}

void pqInitialize(TPriorityQueue* pq, int sz) {
	pq->size = 0;
	pq->heap = (HeapNode*)malloc(sizeof(HeapNode)*(sz+1));
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
	if(pq->size == 0) return 1;
	return 0;
}

#pragma once

#include <stdlib.h>
#include <stdio.h>

typedef struct pair{
	double fst; 
	int snd;
} TPair;

typedef TPair HeapNode ;

typedef struct PQ {
    HeapNode* heap;
    int size;
} TPriorityQueue; 


int pqCmp(TPair x, TPair y);
void pqInsert(HeapNode nodo, HeapNode* heap, int size);
void pqRestore(HeapNode* heap, int size, int idx);
HeapNode pqRemoveRoot(HeapNode* heap, int size);
void pqInitialize(TPriorityQueue* pq, int sz);
void pqPush(TPriorityQueue* pq, HeapNode node);
HeapNode pqTop(TPriorityQueue *pq);
int pqEmpty(TPriorityQueue *pq);
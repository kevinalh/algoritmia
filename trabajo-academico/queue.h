#pragma once

#include <stdlib.h>

typedef int TQElement;

typedef struct queueNode {
	TQElement value;
	struct queueNode* next;
} TQNode;

typedef struct queue {
	TQNode* last;
	TQNode* first;
} TQueue;

void queueInitialize(TQueue* q);
int queueIsEmpty(TQueue* q);
void queueInsert(TQueue* q, TQElement value);
TQElement queuePop(TQueue* q);
void queueClean(TQueue* q);

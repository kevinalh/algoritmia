/*! \file */
#include <stdlib.h>

#include "queue.h"
#include "graph.h"

void queueInitialize(TQueue* q) {
	q->first = NULL;
	q->last = NULL;
	return;
}

int queueIsEmpty(TQueue* q) {
	return q->first == NULL;
}

void queueInsert(TQueue* q, TQElement value) {
	TQNode* node = malloc(sizeof(TQNode));
	node->next = NULL;
	node->value = value;
	if (queueIsEmpty(q)) {
		q->first = node;
		q->last = node;
	}
	else {
		q->last->next = node;
		q->last = node;
	}
	return;
}

TQElement queuePop(TQueue* q) {
	if (queueIsEmpty(q)) reportError("Queue logic");
	TQNode* node = q->first;
	TQElement value = node->value;
	q->first = node->next;
	free(node);
	return value;
}

void queueClean(TQueue* q) {
	while (!queueIsEmpty(q)) {
		queuePop(q);
	}
	return;
}

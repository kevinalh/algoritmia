#include <stdlib.h>

typedef struct element {
    int value;
    element* next;
} element;

typedef struct queue {
    element* first;
} queue;

void create(queue* q) {
    q = malloc(sizeof(queue));
    return;
}

void enqueue(queue* q, int a) {
    element b;
    b.value = a;
    b.next = q.first;
    q.first = &b;
    return;
}

int dequeue(queue* q) {
    int a = q->first->value;

    free(q->first);
    return a;
}

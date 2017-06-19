#ifndef COLA_H
#define	COLA_H

#include <stdio.h>
#include <stdlib.h>

typedef char TElement;

typedef struct Node {
    TElement value;
    struct Node* next;
} TNode;

/* Queue */

typedef struct Queue {
    TNode* start;
    TNode* end;
} TQueue;

void Queue_init(TQueue* queue) {
    queue->start = NULL;
    queue->end = NULL;
    return;
}

void print_Error(char* s) {
    printf("%s error.\n", s);
    return;
}

int Queue_isEmpty(TQueue* queue) {
    return queue->start == NULL;
}

void Queue_enqueue(TQueue* queue, TElement a) {
    TNode* node = malloc(sizeof(TNode));
    if(node) {
        node->next = NULL;
        node->value = a;
        if(Queue_isEmpty(queue)) {
            queue->start = node;
            queue->end = node;
        }
        else {
            queue->end->next = node;
            queue->end = node;
        }
    } else {
        print_Error("Memory");
    }
    return;
}

TElement Queue_head(TQueue* queue) {
    TElement a;
    if(!Queue_isEmpty(queue)) {
        a = queue->start->value;
    } else {
        a = -1;
    }
    return a;
}

TElement Queue_dequeue(TQueue* queue) {
    TElement a = Queue_head(queue);
    TNode* tmp;
    if(!Queue_isEmpty(queue)) {
        tmp = queue->start;
        queue->start = tmp->next;
        free(tmp);
    }
    return a;
}

void Queue_clean(TQueue* queue) {
    while(!Queue_isEmpty(queue)) {
        Queue_dequeue(queue);
    }
    return;
}

/* Stack */

typedef struct Stack {
    TNode* top;
} TStack;

void Stack_init(TStack* stack) {
    stack->top = NULL;
    return;
}

int Stack_isEmpty(TStack* stack) {
    return (stack->top == NULL) ? 1 : 0;
}

TElement Stack_top(TStack* stack) {
    if(!Stack_isEmpty(stack)) {
        return stack->top->value;
    }
    else {
        return '?';
    }
}

TElement Stack_pop(TStack* stack) {
    TElement a = Stack_top(stack);
    if(!Stack_isEmpty(stack)) {
        TNode* b = stack->top;
        stack->top = b->next;
        free(b);
    }
    return a;
}

void Stack_push(TStack* stack, TElement v) {
    TNode* a = malloc(sizeof(TNode));
    a->value = v;
    a->next = NULL;
    if(a) {
        a->next = stack->top;
        stack->top = a;
    } else {
        print_Error("Memory");
    }
    return;
}

void Stack_clean(TStack* stack) {
    while(!Stack_isEmpty(stack)) {
        Stack_pop(stack);
    }
    return;
}

#endif
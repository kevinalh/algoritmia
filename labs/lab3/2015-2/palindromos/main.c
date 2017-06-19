#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "queue.h"

#define MAXS 1000

void esPalindromo(TStack* stack, TQueue* queue) {
    char a, b;
    while(!Stack_isEmpty(stack)) {
        a = Stack_pop(stack);
        b = Queue_dequeue(queue);
        if(a != b) {
            printf("Falso\n");
            return;
        }
    }
    printf("Verdadero\n");
    return;
}

int main() {
    char a = ' ';
    TQueue queue;
    TStack stack;
    Stack_init(&stack);
    Queue_init(&queue);
    int condicion = 0;
    while(condicion < 2) {
        scanf("%c", &a);
        if(a == '\n' || a == '\r') {
            condicion++;
            if(condicion < 2) {
                esPalindromo(&stack, &queue);
            }
            Stack_clean(&stack);
            Queue_clean(&queue);
            continue;
        }
        condicion = 0;
        if(!isalpha(a)) continue;
        a = tolower(a);
        Queue_enqueue(&queue, a);
        Stack_push(&stack, a);
    };
    return (EXIT_SUCCESS);
}


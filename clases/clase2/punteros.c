#include <stdio.h>
#include <stdlib.h>

void addAndSubstract(int a, int b, int* sum, int* diff);

int main(void){
    int a = 15;
    int b = 4;
    int *c = &a;

    int *sum = malloc(sizeof(int));
    int *diff = malloc(sizeof(int));

    // Devuelve el valor de a
    printf("a = %d\n", a);
    // Devuelve la dirección de a
    printf("&a = %d\n", &a);
    // Devuelve el valor de a
    printf("*c = %d\n", *c);
    // Devuelve la dirección de a
    printf("c = %d\n", c);

    addAndSubstract(a, b, sum, diff);
    printf("Suma: %d\n", *sum);
    printf("Resta: %d\n", *diff);

    return 0;
}

void addAndSubstract(int a, int b, int* sum, int* diff){
    *sum = a+b;
    *diff = a-b;
}

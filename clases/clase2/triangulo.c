#include <stdio.h>
#include <stdlib.h>

void triangulo(int, int);

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    triangulo(a, b);
    return (EXIT_SUCCESS);
}

void triangulo(int a, int b) {
    int i;
    for(i = 0; i < a; i++) {
        printf("*");
    }
    printf("\n");
    if(a+1 <= b) triangulo(a+1, b);
    for(i = 0; i < a; i++) {
        printf("*");
    }
    printf("\n");
    return;
}

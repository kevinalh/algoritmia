#include <stdio.h>

#define MAX 20

int main() {
    int n = 9;
    int array[MAX] = {1, 1, 1, 5, 3, 1, 10, 3, 21};
    int K = 3;
    for (int i = 0; i <= n-1; i++) {
        if(array[i] == K) {
            printf("El índice donde está %d es: %d\n", K, i);
            return 0;
        }
    }
    printf("No se encontró el número %d\n", K);
    return 0;
}

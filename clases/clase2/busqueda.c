#include <stdio.h>
#include <stdlib.h>

int busqueda(int n, int k, int* numeros);

int main() {
    int i, n, k;
    scanf("%d", &n);
    int* numeros = malloc(n*sizeof(int));
    for(i = 0; i < n; i++) {
        scanf("%d", &numeros[i]);
    }
    printf("Numero a buscar: ");
    scanf(" %d", &k);
    printf("%d", busqueda(n, k, numeros));
    return 0;
}

int busqueda(int n, int k, int* numeros) {
    if (numeros[n] == k) return n;
    else if (n == 0) return -1;
    else return busqueda(n-1, k, numeros);
}
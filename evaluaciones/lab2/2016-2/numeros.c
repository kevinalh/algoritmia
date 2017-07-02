#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXN 100001

int numeros(long enteros[MAXN], int n, long d, long arreglo[3], int cantidad);
bool esValido(long a, long arreglo[3], int cantidad, long d);
long abs(long a);

int main() {
    int i, n, cuantos = 0;
    long d;
    long enteros[MAXN];
    long arreglo[3] = {0, 0, 0};
    scanf("%d %ld", &n, &d);
    for(i = 0; i < n; i++) {
        scanf("%ld", &enteros[i]);
    }
}

int numeros(long enteros[MAXN], int n, long d, long arreglo[3], int cantidad) {
    if(*cuantos == 3) return 1;
    int i;
    for(i = 0; i < n; i++) {
        if(esValido(enteros[i], arreglo, cantidad, d))
    }
}

bool esValido(long a, long arreglo[3], int cantidad, long d) {
    if(cantidad == 0) return 1;
    if()
}

long abs(long a) {
    return a < 0 ? -a : a;
}
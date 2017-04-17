#include <stdio.h>
#include <stdlib.h>

#define NMAX 100

int busquedaBinaria(int v[NMAX], int ini, int fin, int k);

int main() {
    int i, n, k;
    scanf("%d", &n);
    int v[NMAX];
    for(i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    scanf("%d", &k);
    int posicion = busquedaBinaria(v, 0, n-1, k);
    if(posicion >= 0)
        printf("Lo encontro en la posicion %d\n", posicion);
    else
        printf("No lo encontro\n");
    return 0;
}


int busquedaBinaria(int v[NMAX], int ini, int fin, int k) {
    if(ini <= fin) {
        int medio = (ini+ fin) / 2;
        if(v[medio] == k)
            return medio;
        if(v[medio] <  k) 
            return busquedaBinaria(v, medio+1, fin, k);
        else
            return busquedaBinaria(v, ini, medio-1, k);
    }
    return -1;
}

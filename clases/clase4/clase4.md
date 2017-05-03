---
title: Algoritmia - Clase 4
geometry: margin=3cm
date: 10 de abril
---

## Comentarios del Laboratorio 1
- Para recorrer las casillas alrededor en el buscaminas, se pudo hacer lo siguiente:

~~~c
for(i = -1; i < 2; i++) {
    for(j = -1; j < 2; j++) {
        if (validado(matriz, x+i, y+j) && matriz[x+i][y+j] == 'V')
            buscaminas(matriz, x+i, y+j);
    }
}
~~~

# Divide y vencerás
- Consiste en dividir un problema grande en problemas más pequeños de la misma forma, hasta que lleguemos a un caso base.
- Se usa cuando se puede descomponer el problema en subproblemas.
- Además, debe ser posible combinar las soluciones de manera eficiente.
- El tamaño de las instancias debe ser el mismo. Se debe evitar dividir y combinar cuando el tamaño de las instancias no se justifica.

## Búsqueda binaria
- Se puede usar una versión iterativa, pero en nuestro caso lo hacemos recursivamente.

~~~{#busquedabinaria .c}
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
~~~

## Mergesort
- Se divide en mitades hasta que sea de tamaño 1.
- Tiene complejidad $\mathcal{O}(n \log n)$.
- A veces se prefiere usar Quicksort, pues en Mergesort cada división crea nuevos vectores paralelos, lo cual ocupa espacio.
- Sin embargo, Quicksort es de complejidad $\mathcal{O}(n^2)$.

## Quicksort
-

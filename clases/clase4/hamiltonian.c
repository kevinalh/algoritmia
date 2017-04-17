#include <stdio.h>
#include <stdlib.h>

#define NMAX 500

int hamiltoniano(int grafo[][NMAX], int n, int solucion[NMAX+1], int recorridos);
int esValido(int grafo[][NMAX], int solucion[NMAX+1], int recorridos, int inicio, int nodo);
void inicializarSolucion(int solucion[NMAX+1]);
void imprimirSolucion(int solucion[NMAX+1], int n);

int main() {
    int i, j, n;
    int grafo[NMAX][NMAX];
    int solucion[NMAX+1];
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &grafo[i][j]);
        }
    }
    inicializarSolucion(solucion);
    for(i = 0; i < n; i++) {
        solucion[0] = i;
        if(hamiltoniano(grafo, n, solucion, 1)) {
            imprimirSolucion(solucion, n);
            return 0;
        }
    }
    printf("No se puede llegar\n");
    return 0;
}

int hamiltoniano(int grafo[][NMAX], int n, int solucion[NMAX], int recorridos) {
   int i, j;
   imprimirSolucion(solucion, n);
   if(recorridos == n) {
       /* Si existe un camino entre el elemento de la ultima posicion y el elemento inicial */
       if(grafo[solucion[n-1]][solucion[0]]) {
           solucion[recorridos] = solucion[0];
           return 1;
       } else return 0;
   }
   for(i = 0; i < n; i++) {
       if(esValido(grafo, solucion, recorridos, solucion[recorridos], i)){
           solucion[recorridos] = i;
           recorridos++;
           if(hamiltoniano(grafo, n, solucion, recorridos)) {
               return 1;
           }
           solucion[recorridos] = -1;
           recorridos--;
       }
   }
   return 0;
}

void inicializarSolucion(int solucion[NMAX]) {
    int i;
    for(i = 0; i < NMAX; i++) {
        solucion[i] = 0;
    }
    return;
}

int esValido(int grafo[][NMAX], int solucion[NMAX+1], int recorridos, int inicio, int nodo) {
    int i;
    for(i = 0; i < recorridos; i++) {
        if(solucion[i] == nodo)
            return 0;
    }
    if(grafo[inicio][i]) return 1;
    else return 0;
}

void imprimirSolucion(int solucion[NMAX], int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("%d ", solucion[i]);
    }
    printf("\n");
    return;
}

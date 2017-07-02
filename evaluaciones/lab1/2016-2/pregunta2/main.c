/* 
 * 2016-2
 * Laboratorio 1
 * Pregunta 2
 * 
 * Estrategia empleada: Recursión
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_TABLERO 30

int max(int, int);
int puntaje(int, int, int, int, int[][MAX_TABLERO]);

int main() {
    int n, m, i, j;
    // Lee las dimensiones del tablero
    scanf("%d %d", &n, &m);
    int tablero[n][m];
    // Lee los valores del tablero para cada casilla
    for(i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &tablero[i][j]);
        }
    }
    printf("Máximo puntaje: %d\n", puntaje(n, m, 0, 0, tablero));
    return (EXIT_SUCCESS);
}

// Calcula el puntaje máximo que se puede conseguir en un tablero
int puntaje(int n, int m, int i, int j, int tablero[][m]){
    // Si es la última casilla, devuelve el valor de la misma
    if(i == n-1 && j == m-1) return tablero[i][j];
    int recursivo = 0;
    if(i == n-1) {
        // Si se está en el borde inferior, sólo se puede avanzar a la derecha
        recursivo = puntaje(n, m, i, j+1, tablero);
    } else if(j == m-1) {
        // Si se está en el borde lateral derecho, sólo se puede
        // avanzar hacia abajo
        recursivo = puntaje(n, m, i+1, j, tablero);
    } else {
        // En general, calcular el máximo conseguido al tomar los caminos
        // hacia abajo y a la derecha
        recursivo = max(puntaje(n, m, i, j+1, tablero),
                        puntaje(n, m, i+1, j, tablero));
    }
    return tablero[i][j] + recursivo;
}

// Calcula el máximo de dos números
int max(int a, int b){
    return a < b ? b : a;
}
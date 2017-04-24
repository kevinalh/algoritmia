#include <stdio.h>
#include <stdlib.h>

#define N 20

int reinas(int tablero[N][N], int n, int dim);
void imprimirTablero(int tablero[N][N], int dim);
void inicializarTablero(int tablero[N][N], int dim);
int esValido(int tablero[N][N], int fila, int columna, int dim);

int main() {
    int n, dim;
    scanf("%d", &n);
    int tablero[N][N];
    inicializarTablero(tablero, n);
    if(reinas(tablero, 0, n)) {
        imprimirTablero(tablero, n);
    } else printf("No se encontro solucion\n");
    return 0;
}

int reinas(int tablero[N][N], int n, int dim) {
    if(n == dim) return 1;
    int i;
    /* Basta revisar sobre cada columna */
    for(i = 0; i < dim; i++) {
        if (esValido(tablero, i, n, dim)) {
            tablero[i][n] = 1;
            if(reinas(tablero, n+1, dim)) return 1;
            else tablero[i][n] = 0;
        }
    }
    return 0;
}

int esValido(int tablero[N][N], int fila, int columna, int dim) {
    int i, j;
    /* Basta revisar a la izquierda, pues no hay piezas a la derecha */
    /* Buscamos alguna reina en la fila */
    for(i = 0; i < columna; i++) {
        if(tablero[fila][i]) return 0;
    }
    /* Diagonal \ */
    for(i = fila, j = columna; i >= 0 && j >= 0; i--, j--) {
        if(tablero[i][j]) return 0;
    }
    /* Diagonal / */
    for(i = fila, j = columna; i < dim && j >= 0; i++, j--) {
        if(tablero[i][j]) return 0;
    }
    /* No es necesario revisar las columnas por construccion */
    return 1;
}

void imprimirTablero(int tablero[N][N], int dim) {
    int i, j;
    for(i = 0; i < dim; i++) {
        for(j = 0; j < dim; j++) {
            printf("%d ", tablero[i][j]);
        }
        printf("\n");
    }
    return;
}

void inicializarTablero(int tablero[N][N], int dim) {
    int i, j;
    for(i = 0; i < dim; i++) {
        for(j = 0; j < dim; j++) {
            tablero[i][j] = 0;
        }
    }
    return;
}


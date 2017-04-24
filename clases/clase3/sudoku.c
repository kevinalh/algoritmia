#include <stdio.h>
#include <stdlib.h>

#define N 9

int sudoku(int tabla[N][N], int x, int y);
int esValida(int tabla[N][N], int x, int y, int n);
void imprimirTabla(int tabla[N][N]);

int main() {
    int tabla[N][N];
    int i, j;
    /* Las casillas vacias deben tener un cero */
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            scanf("%d", &tabla[i][j]);
        }
    }
    if(sudoku(tabla, 0, 0)) {
        imprimirTabla(tabla);
    } else {
        printf("No se encontro solucion\n");
    }
    return 0;
}

int sudoku(int tabla[N][N], int x, int y) {
    if(x == N && y == N-1) {
        return 1;
    }
    if(x == N) {
        return sudoku(tabla, 0, y+1);
    }
    if(tabla[x][y] != 0) {
        return sudoku(tabla, x+1, y);
    }
    int n;
    for(n = 1; n <= N; n++) {
        /* Evaluamos si la opcion es valida */
        if(esValida(tabla, x, y, n)) {
            /* Modificamos el tablero */
            tabla[x][y] = n;
            if(sudoku(tabla, x+1, y)) {
                return 1;
            } else {
                tabla[x][y] = 0;
            }
        }
    }
    return 0;
}

int esValida(int tabla[N][N], int x, int y, int n) {
    int i, j;
    /* La fila y la columna no deben contener a n */
    for(i = 0; i < N; i++) {
        if(tabla[x][i] == n || tabla[i][y] == n) return 0;
    }
    /* Revisamos el cuadrante 3x3 */
    /* Hallamos la coordenada (x1, y1) donde empieza el cuadrado */
    int x1 = (x/3)*3;
    int y1 = (y/3)*3;
    for(i = x1; i < x1 + 3; i++) {
        for(j = y1; j < y1 + 3; j++) {
            if(tabla[i][j] == n) return 0;
        }
    }
    return 1;
}

void imprimirTabla(int tabla[N][N]) {
    int i, j, k;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", tabla[i][j]);
            if(j == 2 || j == 5) printf("| ");
        }
        if(i == 2 || i == 5) {
            printf("\n");
            for(k = 0; k < N+2; k++) {
                printf("--");
            }
        }
        printf("\n");
    }
}


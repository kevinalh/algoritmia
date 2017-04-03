#include <stdio.h>
#include <stdlib.h>

#define N 10
#define MAX_MOV 8

int MOV[MAX_MOV][2];

void imprimirMatriz(int A[N][N], int n);
void inicializarMatriz(int A[N][N], int n);
void inicializarMovimientos();
int es_valido(int A[N][N], int n, int x, int y);
int caballero(int A[N][N], int x, int y, int n, int nMov);

int main() {
    int n, x, y;
    scanf("%d", &n);
    scanf("%d %d", &x, &y);
    int tablero[n][n];
    inicializarMatriz(tablero, n);
    inicializarMovimientos();
    tablero[x][y] = 1;
    int res = caballero(tablero, x, y, n, 2);
    if(res)
        imprimirMatriz(tablero, n);
    else
        printf("No hay camino\n");
    return 0;
}

void imprimirMatriz(int A[N][N], int n) {
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    return;
}

void inicializarMatriz(int A[N][N], int n) {
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            A[i][j] = 0;
        }
    }
    return;
}

void inicializarMovimientos() {
    MOV[0][0] = 2; MOV[0][1] = 1;
    MOV[1][0] = 2; MOV[1][1] = -1;
    MOV[2][0] = 1; MOV[2][1] = 2;
    MOV[3][0] = 1; MOV[3][1] = -2;
    MOV[4][0] = -2; MOV[4][1] = 1;
    MOV[5][0] = -2; MOV[5][1] = -1;
    MOV[6][0] = -1; MOV[6][1] = 2;
    MOV[7][0] = -1; MOV[7][1] = -2;
}

int caballero(int A[N][N], int x, int y, int n, int nMov) {
    if (nMov == n*n + 1)
        return 1;
    int i;
    for(i = 0; i < MAX_MOV; i++){
        int newx = x + MOV[i][0];
        int newy = y + MOV[i][1];
        if(es_valido(A, n, newx, newy)) {
            A[newx][newy] = nMov;
            if(caballero(A, newx, newy, n, nMov+1))
                return 1;
            A[newx][newy] = 0; /* deshacer el cambio */
        }
    }
    return 0;
}

int es_valido(int A[N][N], int n, int x, int y) {
     if(x>=0 && x<n && y>=0 && y<n && A[x][y]==0)
         return 1;
     return 0;
}

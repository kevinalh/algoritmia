#include <stdio.h>
#include <stdlib.h>

void transpuesta(int n, int matriz[n][n]);
void imprimirmatriz(int n, int matriz[n][n]);

int main() {
    int N = 0, i = 0, j = 0;
    scanf("%d", &N);
    int matriz[N][N];
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
    imprimirmatriz(N, matriz);
    printf("\n");
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void transpuesta(int n, int matriz[n][n]) {
    if(n == 1) return;
    int tmp = matriz[n-1][0];
    matriz[n-1][0] = matriz[0][n-1];
    matriz[0][n-1] = tmp;
    transpuesta(n-1, matriz);
    return;
}

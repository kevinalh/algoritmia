#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * Cálculo de determinante
 */

int determinante(int n, int matriz[][n]);
void adjunta(int n, int submatriz[][n-1], int matriz[][n], int k);

int main() {
    int i, j, n;
    printf("Ingresar dimension: ");
    scanf("%d", &n);
    int matriz[n][n];
    int det = 0;
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
    det = determinante(n, matriz);
    printf("La determinante es: %d\n", det);
    return (EXIT_SUCCESS);
}

void adjunta(int n, int submatriz[][n-1], int matriz[][n], int k){
    int i = 1, j = 0;
    while(i<n){
        j = 0;
        while(j<n-1) {
            if(j>=k) {
                submatriz[i-1][j] = matriz[i][j+1];
            }
            else {
                submatriz[i-1][j] = matriz[i][j];
            }
            j++;
        }
        i++;
    }
    return;
}

int determinante(int n, int matriz[][n]){
    if(n == 1) return matriz[0][0];
    int k, suma = 0;
    int submatriz[n-1][n-1];
    for (k=0; k<n; k++){
        adjunta(n, submatriz, matriz, k);
        suma += pow(-1, k) * matriz[0][k] * determinante(n-1, submatriz);
    }
    return suma;
}

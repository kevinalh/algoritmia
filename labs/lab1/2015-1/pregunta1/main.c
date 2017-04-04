#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_N 101
#define MAX_M 101

int gcd(int, int);

int main() {
    int i, j, N, M, k;
    int numeros[MAX_N][MAX_M];
    int sizes[MAX_N];
    scanf("%d", &N);
    for(i = 0; i < N; i++) {
        j = 0;
        while(scanf("%d", &numeros[i][j])) {
            if('\n' == getchar()) break;
            else j++;
        }
        sizes[i] = j+1;
    }
    /*
     * Esto no es para nada eficiente: No pasa en UVa por time limit
     * Pero parece ser suficiente para el lab
     */
    int maximo = 1;
    int aux = 0;
    for(i = 0; i < N; i++){
        maximo = 1;
        for(j = 0; j < sizes[i]-1; j++) {
            if(numeros[i][j] <= maximo) continue;
            for(k = j + 1; k < sizes[i]; k++) {
                if(numeros[i][k] < maximo) continue;
                if(numeros[i][j] < maximo) break;
                aux = gcd(numeros[i][j], numeros[i][k]);
                if(aux > maximo) maximo = aux;
            }
        }
        printf("%d\n", maximo);
    }
    return (EXIT_SUCCESS);
}

/*
 *  En el lab piden que sea de forma recursiva
 */

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}
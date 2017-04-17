#include <stdio.h>
#include <stdlib.h>

#define MAX_N 105
#define MAX_M 105

int gcd(int, int);

int main() {
    int i, j, N, M, k;
    int numeros[MAX_M];
    int maximo = 1;
    int aux = 0;
    scanf("%d", &N);
    for(i = 0; i < N; i++) {
        M = 0;
        while(scanf("%d", &numeros[M])) {
            if(getchar() != ' ') break;
            else M++;
        }
        M++;
        maximo = 1;
        for(j = 0; j < M-1; j++) {
            for(k = j + 1; k < M; k++) {
                aux = gcd(numeros[j], numeros[k]);
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
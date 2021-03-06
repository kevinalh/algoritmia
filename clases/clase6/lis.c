#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100

int main() {
    int seq[MAXN];
    int n, i, j;
    scanf("%d", &n);
    for(i = 0; i < n; ++i) {
        scanf("%d", &seq[i]);
    }
    int lis[MAXN];
    lis[0] = 1;
    int max = 0;
    for(i = 1; i < n; ++i) {
        /* Toda secuencia es el fin de la secuencia que solo la contiene */
        lis[i] = 1;
        /* Para cada elemento anterior */
        for(j = 0; j < i; ++j) {
            /* Si el ultimo elemento de la secuencia creciente es menor que el elemento actual,
             * entonces comparamos si el LIS del j-esimo elemento, mas el nuevo elemento, es mayor
             * en longitud que el que tenemos para el i-esimo */
            if(seq[j] < seq[i] && lis[j]+1 > lis[i]) {
                lis[i] = lis[j]+1;
            }
        }
        if(lis[i] > max) {
            max = lis[i];
        }
    }
    printf("Longest Increasing Subsequence: %d\n", max);
    return 0;
}

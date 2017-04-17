/*
 * Pregunta 1 del Lab 1, 2013-1
 * Números triangulares
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1001
#define MAX_n 302

int main() {
    int i, N;
    int puntos[MAX_N];
    int pond[MAX_n];
    scanf("%d", &N);
    for(i = 0; i < N; i++) {
        scanf("%d", &puntos[i]);
    }
    int tri = 1;
    pond[0] = 0;
    for(i = 1; i < MAX_n; i++) {
        tri += i+1;
        pond[i] = pond[i-1] + i*tri;
    }
    for(i = 0; i < N; i++) {
        printf("%d %d %d\n", i+1, puntos[i], pond[puntos[i]]);
    }
    return (EXIT_SUCCESS);
}

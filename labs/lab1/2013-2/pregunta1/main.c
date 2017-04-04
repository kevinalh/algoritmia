/*
 * Pregunta 1 del Lab 2013-2
 * UVa 10130 - SuperSale
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_T 1000
#define MAX_N 1000
#define MAX_P 100
#define MAX_W 30
#define MAX_G 100
#define MAX_MW 30

int main() {
    int i = 0, T = 0, N = 0, G = 0, j = 0;
    int precios[MAX_N];
    int pesos[MAX_N];
    int personas[MAX_G];
    scanf("%d", &T);
    for(i = 0; i < T; i++) {
        scanf("%d", &N);
        for(j = 0; j < N; j++) {
            scanf("%d %d", &precios[j], &pesos[j]);
        }
        scanf("%d", &G);
        for(j = 0; j < G; j++) {
            scanf("%d", &personas[j]);
        }
        
    }
    return (EXIT_SUCCESS);
}


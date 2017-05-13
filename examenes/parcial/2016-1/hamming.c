/* 
UVa
729 - The Hamming Distance Problem
(Usando Backtracking como se pide en el examen)
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void imprimir(int n, int num[n]) {
    int i;
    for(i = 0; i < n; ++i) {
        printf("%d", num[i]);
    }
    printf("\n");
    return;
}

void ham(int n, int num[n], int h, int c, int s) {
    /* s: current sum of ones
     c: current position */
    if(s == h) {
        imprimir(n, num);
        return;
    }
    int i;
    for(i = n-1; i >= c; --i) {
        if(num[i] == 1) continue;
        num[i] = 1;
        ham(n, num, h, i, s+1);
        num[i] = 0;
    }
    return;
}

int main() {
    long long sets, i;
    int n, h;
    scanf("%d", &sets);
    for(i = 0; i < sets; ++i) {
        if(i != 0) printf("\n");
        scanf("%d %d", &n, &h);
        int num[n];
        memset(num, 0, n*sizeof(int));
        ham(n, num, h, 0, 0);
    }
    return 0;
}
/*
HackerRank
Nikita and the Game
https://www.hackerrank.com/challenges/array-splitting
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define NMAX 16390

int a[NMAX], sl[NMAX], sr[NMAX];
int n;

int max(int a, int b) {
    return a > b ? a : b;
}

void imprimir(int low, int high, int c[NMAX]) {
    int i;
    for(i = low; i < high; ++i) {
        printf("%d ", c[i]);
    }
    printf("\n");
    return;
}

void corte(int low, int high) {
    int i, j, sz = high - low;
    sl[0] = a[low];
    sr[sz-1] = a[high-1];
    /*
    sl[i]: sum of the first i elements
    sr[i]: sum of the elements i,... high-1
    */
    for(i = 1; i < sz; ++i) {
        sl[i] = sl[i-1] + a[low+i];
        sr[sz-1-i] = sr[sz-i] + a[high-1-i];
    }
    return;
}

int points(int low, int high) {
    /* Only the first possible split is needed */
    if(low >= high || low == high-1) {
        return 0;
    }
    int i, sz = high-low, maxpts = 0, currpts = 0, entro = 0;
    corte(low, high);
    /*printf("low: %d; high: %d;\n", low, high);
    imprimir(0, sz, sl);
    imprimir(0, sz, sr);*/
    for(i = 0; i < sz-1; ++i) {
        if(sl[i] == sr[i+1]) {
            currpts = max(points(low, low+i+1), points(low+i+1, high));
            maxpts = currpts > maxpts ? currpts : maxpts;
            entro = 1;
            break;
        }
    }
    if(entro == 0) {
        return 0;
    }
    return maxpts+1;
}

int main() {
    int i, t, tests, pts;
    scanf("%d", &tests);
    for(t = 0; t < tests; ++t) {
        scanf("%d", &n);
        for(i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        pts = points(0, n);
        printf("%d\n", pts);
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 30

typedef struct edge {
    int x;
    int y;
} edge;

int n, m;
edge edges[MAXN*3];
int visitadas[MAXN*3];

int incluido(int lado) {
    int i;
    for(i = 0; i < m; i++) {
        if(lado == visitadas[i]) return 1;
    }
    return 0;
}

int longest(int nodo, int longitud) {
    int i, max = longitud, tmp = 0, nuevo = -1;
    for(i = 0; i < m; i++) {
        if(!incluido(i)) {
            if(edges[i].x == nodo) nuevo = edges[i].y;
            else if(edges[i].y == nodo) nuevo = edges[i].x;
            else continue;
            visitadas[longitud] = i;
            tmp = longest(nuevo, longitud + 1);
            if(tmp > max) max = tmp;
            visitadas[longitud] = -1;
        }
    }
    return max;
}

int main() {
    int i, edge1, edge2, max, tmp;
    while(scanf("%d %d", &n, &m)) {
        if(n == 0 && m == 0) break;
        memset(edges, 0, MAXN*3*sizeof(edge));
        for(i = 0; i < m; i++) {
            scanf("%d %d", &edge1, &edge2);
            edges[i].x = edge1;
            edges[i].y = edge2;
        }
        max = 0;
        for(i = 0; i < n; i++) {
            memset(visitadas, -1, MAXN*3*sizeof(int));
            tmp = longest(i, 0);
            if(tmp > max) max = tmp;
        }
        printf("%d\n", max);
    }
    return 0;
}
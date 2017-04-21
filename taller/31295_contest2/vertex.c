#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 101

void inicializarGrafo(int graph[MAXN][MAXN], int n);
int accesible(int graph[MAXN][MAXN], int start, int end, int n, int recorrido[MAXN]);
void anexar(int recorrido[MAXN], int num, int n);
void quitar(int recorrido[MAXN], int n);
int esValido(int graph[MAXN][MAXN], int start, int i, int recorrido[MAXN], int n);
int ultimo(int recorrido[MAXN], int n);

int main() {
    int graph[MAXN][MAXN];
    int inaccesibles[MAXN];
    int ninaccesibles = 0;
    int recorrido[MAXN];
    int n = 0, i = 0, j = 0, inv = 0, current;
    while(scanf("%d", &n) && n != 0) {
        /* n = Number of vertices in the graph */
        inicializarGrafo(graph, n);
        while(scanf("%d", &i) && i != 0) {
            while(scanf("%d", &j) && j != 0) {
                /* We take 1 so that the matrix starts at zero */
                graph[i-1][j-1] = 1;
            }
        }
        scanf("%d", &inv);
        for(i = 0; i < inv; i++) {
            memset(inaccesibles, -1, sizeof(inaccesibles));
            ninaccesibles = 0;
            scanf("%d", &current);
            current--; /* Para empezar en cero */
            for(j = 0; j < n; j++) {
                memset(recorrido, -1, sizeof(recorrido));
                if(!accesible(graph, current, j, n, recorrido)) {
                    anexar(inaccesibles, j, n);
                    ninaccesibles++;
                }
            }
            printf("%d", ninaccesibles);
            for(j = 0; j < ninaccesibles; j++) {
                printf(" %d", inaccesibles[j] + 1);
            }
            printf("\n");
        }
    }
    return 0;
}

int accesible(int graph[MAXN][MAXN], int start, int end, int n, int recorrido[MAXN]) {
    if(ultimo(recorrido, n) == end) return 1;
    int i;
    for(i = 0; i < n; i++) {
        if(esValido(graph, start, i, recorrido, n)) {
            anexar(recorrido, i, n);
            if(accesible(graph, i, end, n, recorrido)) {
                return 1;
            }
            quitar(recorrido, n);
        }
    }
    return 0;
}

int ultimo(int recorrido[MAXN], int n) {
    int i;
    if(recorrido[0] == -1) return -1;
    for(i = 1; i < n; i++) {
        if(recorrido[i] == -1) return recorrido[i-1];
    }
    return -1;
}

void anexar(int recorrido[MAXN], int num, int n) {
    int i;
    for(i = 0; i < n; i++) {
        if(recorrido[i] == -1) {
            recorrido[i] = num;
            return;
        }
    }
    return;
}

void quitar(int recorrido[MAXN], int n) {
    int i;
    for(i = 0; i <= n; i++) {
        if(i == n) {
            recorrido[n-1] = -1;
            return;
        }
        if(recorrido[i] == -1) {
            recorrido[i - 1] = -1;
            return;
        }
    }
    return;
}

int esValido(int graph[MAXN][MAXN], int start, int i, int recorrido[MAXN], int n) {
    if(!graph[start][i]) return 0;
    int j;
    /* Queremos evitar loops */
    for(j = 0; j < n; j++) {
        if(recorrido[j] == -1) break;
        if(recorrido[j] == i ) return 0;
    }
    return 1;
}

void inicializarGrafo(int graph[MAXN][MAXN], int n) {
    int i;
    for(i = 0; i < n; i++) {
        memset(graph[i], 0, n);
    }
    return;
}
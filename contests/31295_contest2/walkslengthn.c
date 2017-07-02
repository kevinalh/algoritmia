#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 11
#define MAXWALKS 6

void productoMatricial(int aN[MAXN][MAXN]);
int findWalk(int start, int end, int currentwalk[MAXN], int currentlen);
int incluido(int node, int currentwalk[MAXN], int currentlen);
void imprimirMatriz(int matriz[MAXN][MAXN], int longitud);
int compararCaminos(int a[MAXN], int b[MAXN]);
void swap(int a[MAXN], int b[MAXN]);

int nwalks;
int len;
int m;
int walks[MAXWALKS][MAXN];
int graph[MAXN][MAXN];

int main() {
    int i, j, suma, swapped = 0;
    int adjN[MAXN][MAXN];
    int currentwalk[MAXN];
    char input[20];
    char c;
    char* token;
    char* trash;
    /* m = number of nodes
     * adj = adjacency matrix
     * walks = walks of length len
     */
    while(fgets(input, 20, stdin)) {
        if(strcmp(input, "\n") == 0) break;
        token = strtok(input, " ");
        m = (int) strtol(token, &trash, 10);
        if(m == -9999) {
            printf("\n");
            continue;
        }
        token = strtok(NULL, " ");
        len = (int) strtol(token, &trash, 10);
        for(i = 0; i < m; i++) {
            for(j = 0; j < m; j++) {
                scanf("%d", &graph[i][j]);
                adjN[i][j] = graph[i][j];
            }
        }
        memset(walks, -1, MAXWALKS*MAXN*sizeof(int));
        for(i = 0; i < m; i++) {
            walks[i][0] = 0;
        }
        nwalks = 0;
        suma = 0;
        /* len es el numero de lados, si le sumamos 1 es el num de vertices */
        len += 1;
        /* Hacemos que adjN sea adj^len */
        for(i = 1; i < len - 1; i++) {
            productoMatricial(adjN);
        }
        for(i = 1; i < m; i++) {
            /* Usamos la simetria de la matriz */
            memset(currentwalk, -1, MAXN*sizeof(int));
            currentwalk[0] = 0;
            if(adjN[0][i] == 1)
                suma += findWalk(0, i, currentwalk, 1);
        }
        if(suma != nwalks) {
            /* Debugging */
            printf("Something went wrong\n");
        }
        /* Orden lexicografico */
        do {
            swapped = 0;
            for(i = 1; i < nwalks; i++) {
                if(!compararCaminos(walks[i], walks[i-1])) {
                    swap(walks[i], walks[i-1]);
                    swapped = 1;
                }
            }
        } while(swapped);
        for(i = 0; i < nwalks; i++) {
            printf("(1");
            for(j = 1; j < len; j++) {
                printf(",%d", walks[i][j]+1);
            }
            printf(")\n");
        }
        if(nwalks == 0) printf("no walk of length %d\n", len-1);
        while((c = getchar()) != '\n' && c != EOF);
    }
    return 0;
}

void productoMatricial(int aN[MAXN][MAXN]) {
    int i, j, k;
    int tmp[MAXN][MAXN];
    memset(tmp, 0, sizeof(int)*MAXN*MAXN);
    for(i = 0; i < m; i++) {
        for(j = 0; j < m; j++) {
            for(k = 0; k < m; k++) {
                if(aN[i][k] == 1 && graph[k][j] == 1) {
                    tmp[i][j] = 1;
                    break;
                }
            }
        }
    }
    memcpy(aN, tmp, MAXN*MAXN*sizeof(int));
    return;
}

int findWalk(int start, int end, int currentwalk[MAXN], int currentlen) {
    int i, suma = 0;
    if(start == end && currentlen == len) {
        /* Si ya lo encontro, ponemos el camino en la lista */
        /* TODO: Falta la observacion de que, si lo encuentra pero
        la longitud es menor, devuelva cero */
        memcpy(walks[nwalks], currentwalk, MAXN*sizeof(int));
        nwalks++;
        return 1;
    }
    /* Si la longitud es mayor o igual que len, y no es el punto final, 
    se sobrepaso el limite*/
    if(currentlen >= len) return 0;
    for(i = 0; i < m; i++) {
        /* Verificamos que se pueda ir al nodo, y que no se haya usado antes */
        if(i != start && graph[start][i] && !incluido(i, currentwalk, currentlen)) {
            currentwalk[currentlen] = i;
            suma += findWalk(i, end, currentwalk, currentlen + 1);
            currentwalk[currentlen] = -1;
        }
    }
    return suma;
}

int incluido(int node, int currentwalk[MAXN], int currentlen) {
    int i;
    for(i = 0; i < currentlen; i++) {
        if(currentwalk[i] == node) return 1;
    }
    return 0;
}

void imprimirMatriz(int matriz[MAXN][MAXN], int longitud) {
    int i, j;
    /* Debugging */
    printf("\n");
    for(i = 0; i < longitud; i++) {
        for(j = 0; j < longitud; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void swap(int* a, int* b) {
    int tmp[MAXN];
    memcpy(tmp, b, MAXN*sizeof(int));
    memcpy(b, a, MAXN*sizeof(int));
    memcpy(a, tmp, MAXN*sizeof(int));
    return;
}

int compararCaminos(int a[MAXN], int b[MAXN]) {
    /* Devuelve 1 si a > b */
    int i;
    for(i = 0; i < len; i++) {
        if(a[i] == b[i]) continue;
        if(a[i] > b[i]) return 1;
        else break;
    }
    return 0;
}
/*
UVa 10116 - Robot Motion
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 11

char grid[MAXN][MAXN];
int xrecorrido[MAXN*MAXN];
int yrecorrido[MAXN*MAXN];
int rows, columns, enter;

int main() {
    int i, j;
    while(scanf("%d %d %d", &rows, &columns, &enter)) {
        if(rows == 0 && columns == 0 && enter == 0) break;
        enter--; /* Para empezar en cero */
        for(i = 0; i < rows; i++) {
            for(j = 0; j < columns; j++) {
                grid[i][j] = getchar();
            }
            getchar(); /* newline */
        }
        memset(xrecorrido, -1, MAXN*MAXN*sizeof(int));
        memset(yrecorrido, -1, MAXN*MAXN*sizeof(int));
        i = 0;
        j = enter;
        while(salio)
    }
    return 0;
}
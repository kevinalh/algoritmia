#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXN 101

char grid[MAXN][MAXN];
int a, b, c, d, n;

int sepuedeh(int x, int y, int h)  {
    int i;
    if(h == x || grid[h][y] == 'X') return 0;
    for(i = x; i != h; h>x?++i:--i) {
        if(grid[i][y] == 'X') return 0;
    }
    return 1; 
}

int sepuedev(int x, int y, int v) {
    int i;
    if(v == y || grid[x][v] == 'X') return 0;
    for(i = y; i != v; v>y?++i:--i) {
        if(grid[x][i] == 'X') return 0;
    }
    return 1;
}

int go(int x, int y, int pasos) {
    printf("%d %d %d\n", x, y, pasos);
    if(x == c && y == d) {
        return pasos;
    }
    int i, j, min = 102, tmp;
    grid[x][y] = 'X';
    /* horizontalmente */
    for(i = 0; i < n; ++i) {
        if(!sepuedeh(x, y, i)) continue;
        tmp = go(i, y, pasos+1);
        min = tmp < min ? tmp : min;
    }
    /* verticalmente */
    for(i = 0; i < n; ++i) {
        if(!sepuedev(x, y, i)) continue;
        tmp = go(x, i, pasos+1);
        min = tmp < min ? tmp : min;
    }
    grid[x][y] = '.';
    return min;
}

int main() {
    int i, j;
    scanf("%d", &n);
    for(i = 0; i < n; ++i) {
        getchar();
        for(j = 0; j < n; ++j) {
            scanf("%c", &grid[i][j]);
        }
    }
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int minimo = go(a, b, 0);
    printf("%d\n", minimo);
    return 0;
}

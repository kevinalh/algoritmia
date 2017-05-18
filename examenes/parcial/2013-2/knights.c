/*
UVa
10422 - Knights in FEN
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5
#define min(a, b) (((a)<(b)) ? (a) : (b))

int t[N][N];

int movex[9];
int movey[9];

void imt() {
    int i, j;
    for(i = 0; i < N; ++i) {
        for(j = 0; j < N; ++j) {
            printf("%d ", t[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return;
}

void fillmoves() {
    movex[0] = -2; movey[0] = 1;
    movex[1] = -2; movey[1] = -1;
    movex[2] = 2; movey[2] = 1;
    movex[3] = 2; movey[3] = -1;
    movex[4] = -1; movey[4] = 2;
    movex[5] = -1; movey[5] = -2;
    movex[6] = 1; movey[6] = 2;
    movex[7] = 1; movey[7] = -2;
}

int worthtrying(int x, int y, int a, int b) {
    if(t[a][b] == 2) return 0;
    if(x == 2 && y == 2) return 1;
    /* positions for black pieces */
    if(y==0 || (y==1&&x>=1) || (y==2&&x>=3) || (y==3&&x==4)) {
        return t[a][b] == 1;
    }
    if(y==4 || (y==3&&x<=3) || (y==2&&x<=1) || (y==1&&x==0)) {
        return t[a][b] == 0;
    }
    return 0;
}

int correcto() {
    int i, j;
    if(t[2][2] != 2) return 0;
    for(i = 0; i < N; ++i) {
        for(j = i<2?i:i+1; j < N; ++j) {
            if(t[i][j] != 1) return 0;
        }
        for(j = 0; i<3 ? j<i : j<i+1; ++j) {
            if(t[i][j] != 0) return 0;
        }
    }
    return 1;
}

int resolver(int x, int y, int n) {
    /* (x,y) son las coordenadas del casillero vacio */
    if(correcto()) return n;
    if(n >= 11) {
        return 11;
    }
    int i, j, a, b, minimo = 11;
    /* for all possible moves towards the empty cell */
    for(i = 0; i < 8; ++i) {
        a = x + movex[i];
        b = y + movey[i];
        if((a>=0 && a<N) && (b>=0 && b<N)) {
            /*if(!worthtrying(x, y, a, b)) continue;*/
            t[x][y] = t[a][b];
            t[a][b] = 2;
            minimo = min(resolver(a, b, n+1), minimo);
            t[a][b] = t[x][y];
            t[x][y] = 2;
        }
    }
    return minimo;
}

int main() {
    int i, j, input, inputs, x, y, n;
    char fila[N+5];
    fillmoves();
    fgets(fila, N+1, stdin);
    inputs = atoi(fila);
    for(input = 0; input < inputs; ++input) {
        for(i = 0; i < N; ++i) {
            fgets(fila, N+5, stdin);
            for(j = 0; j < N; ++j) {
                switch(fila[j]) {
                    case '0':
                        t[i][j] = 0;
                        break;
                    case '1':
                        t[i][j] = 1;
                        break;
                    default:
                        t[i][j] = 2;
                        x = i;
                        y = j;
                        break;
                }
            }
        }
        n = resolver(x, y, 0);
        if(n >= 11) {
            printf("Unsolvable in less than 11 move(s).\n");
        } else {
            printf("Solvable in %d move(s).\n", n);
        }
    }  
    return 0;
}
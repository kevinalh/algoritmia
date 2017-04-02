#include <stdio.h>

int revHor(char[][4], int);
int revVer(char[][4], int);
int revDiagIz(char[][4]);
int revDiagDe(char[][4]);

int main() {
    int i, j, k;
    char tictac[4][4];
    for(i=0; i<4; i++) {
        scanf(" %c%c%c%c", &tictac[i][0], &tictac[i][1],
                            &tictac[i][2], &tictac[i][3]);
    }
    for(i = 0; i < 4; i++) {
        if(revHor(tictac, i) || revVer(tictac, i)) {
            printf("YES");
            return 0;
        }
    }
    if (revDiagIz(tictac) || revDiagDe(tictac)) {
        printf("YES");
        return 0;
    }
    printf("NO\n");
    return 0;
}

int revHor(char tictac[][4], int f) {
    int i, j, X, espacios;
    for(i = 0; i <= 1; i++) {
        X = 0;
        espacios = 0;
        for(j = i; j <= i+2; j++) {
            if(tictac[f][j] == 'x') {
                X++;
            } else if(tictac[f][j] == 'o') {
                X = 0;
                break;
            } else {
                espacios++;
            }
        }
        if(espacios == 1 && X == 2) {
            return 1;
        }
    }
    return 0;
}

int revVer(char tictac[][4], int c) {
    int i, j, X, espacios;
    for(i = 0; i <= 1; i++) {
        X = 0;
        espacios = 0;
        for(j = i; j <= i+2; j++) {
            if(tictac[j][c] == 'x') {
                X++;
            } else if(tictac[j][c] == 'o') {
                X = 0;
                break;
            } else {
                espacios++;
            }
        }
        if(espacios == 1 && X == 2) {
            return 1;
        }
    }
    return 0;
}

int revDiagIz(char tictac[][4]) {
    int i, j, k, X, espacios;
    for(i = 0; i <= 1; i++) {
        for(j = 0; j <= 1; j++) {
            X = 0;
            espacios = 0;
            for(k = 0; k < 3; k++) {
                if(tictac[i+k][j+k] == 'x') {
                    X++;
                } else if(tictac[i+k][j+k] == 'o') {
                    X = 0;
                    break;
                } else {
                    espacios++;
                }
            }
            if(espacios == 1 && X == 2) return 1;
        }
    }
    return 0;
}

int revDiagDe(char tictac[][4]) {
    int i, j, k, X, espacios;
    for(i = 0; i <= 1; i++) {
        for(j = 2; j <= 3; j++) {
            X = 0;
            espacios = 0;
            for(k = 0; k < 3; k++) {
                if(tictac[i+k][j-k] == 'x') {
                    X++;
                } else if(tictac[i+k][j-k] == 'o') {
                    X = 0;
                    break;
                } else {
                    espacios++;
                }
            }
            if(espacios == 1 && X == 2) return 1;
        }
    }
    return 0;
}

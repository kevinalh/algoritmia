#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXW 100
#define MAXN 100

int max(int a, int b);
int mochila(int w[MAXN+1], int v[MAXN+1], int W, int N);

int main() {
    int i, j, N, W;
    scanf("%d", &N);
    scanf("%d", &W);
    int w[MAXN+1];
    int v [MAXN+1];
    for(i = 0; i < N; ++i) {
        
    }
    int valor = mochila(w, v, W, N);
    printf("Valor maximo: %d\n", valor);
    return 0;
}

int mochila(int w[MAXN+1], int v[MAXN+1], int W, int N) {
    int dp[MAXN+1][MAXW+1] = {{}};
    int i, j;
    for(i = 1; i <= N; ++i) {
        for(j = 1; j <= W; ++j) {
            if(w[i-1] > j) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(v[i-1] + dp[i-1][j-w[i-1]], dp[i-1][j]);
            }
        }
    }
    return dp[N][W];
}

int max(int a, int b) {
    return a > b ? a : b;
}

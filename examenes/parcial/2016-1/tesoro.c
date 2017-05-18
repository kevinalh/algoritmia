/*
UVa
990 - Diving for Gold
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 35
#define MAXT 1005

#define max(a, b) (((a) > (b)) ? (a) : (b))

int main() {
    /* t: how much time the air bottle allows under water
    w: constant that defines the ascent/descent time
    n: number of treasures */
    char c;
    int t, w, n, i, j, suma, in = 0;
    int depth[MAXN], gold[MAXN], cost[MAXN];
    int ks[MAXT][MAXN];
    int treasures[MAXN];
    while(scanf("%d %d", &t, &w) == 2) {
        if(in == 0) ++in;
        else printf("\n");
        scanf("%d", &n);
        for(i = 0; i < n; ++i) {
            scanf("%d %d", &depth[i], &gold[i]);
            cost[i] = 3*w*depth[i];
        }
        for(i = 0; i <= t; ++i) {
            for(j = 0; j <= n; ++j) {
                ks[i][j] = 0;
            }
        }
        for(j = 1; j <= n; ++j) {
            for(i = 0; i <= t; ++i) {
                if(cost[j-1] > i) {
                    ks[i][j] = ks[i][j-1];
                } else {
                    ks[i][j] = max(ks[i][j-1], gold[j-1]+ks[i-cost[j-1]][j-1]);
                }
            }
        }
        printf("%d\n", ks[t][n]);
        memset(treasures, 0, MAXN*sizeof(int));
        j = n;
        i = t;
        suma = 0;
        while(j > 0 && i > 0) {
            /* was this object included? */
            if(i>=cost[j-1] && ks[i][j] == gold[j-1]+ks[i-cost[j-1]][j-1]) {
                treasures[j-1] = 1;
                ++suma;
                i -= cost[j-1];
            }
            --j;
        }
        printf("%d\n", suma);
        for(i = 0; i < n; ++i) {
            if(treasures[i]) {
                printf("%d %d\n", depth[i], gold[i]);
            }
        }
    }
    return 0;
}
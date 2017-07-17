#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAXM 50005
#define MAXN 20005

int lt[MAXN][MAXN];
int n, m;

int minNotVisited(int vis[MAXN], int dist[MAXN]) {
    int i, pos = -1, w = INT_MAX;
    for(i = 0; i < n; ++i) {
        if(vis[i] == 0 && dist[i] < w) {
            w = dist[i];
            pos = i;
        }
    }
    return pos;
}

int dijkstra(int s, int t) {
    int i, k, c = n;
    int vis[MAXN];
    int dist[MAXN];
    for(i = 0; i < n; ++i) {
        vis[i] = 0;
        dist[i] = INT_MAX;
    }
    dist[s] = 0;
    while(c--) {
        k = minNotVisited(vis, dist);
        if(k == -1) break;
        for(i = 0; i < n; ++i) {
            if(lt[i][k] != INT_MAX && lt[i][k]+dist[k]<dist[i]) {
                dist[i] = lt[i][k]+dist[k];
            }
        }
        vis[k] = 1;
    }
    return dist[t];
}

int main() {
    int i, j, s, t, cases, casest, w1, w2, w;
    scanf("%d", &casest);
    cases = casest;
    while(cases--) {
        scanf("%d %d %d %d", &n, &m, &s, &t);
        for(i = 0; i < n; ++i) {
            for(j = 0; j < n; ++j) {
                lt[i][j] = INT_MAX;
            }
        }
        for(i = 0; i < m; ++i) {
            scanf("%d %d", &w1, &w2);
            scanf("%d", &lt[w1][w2]);
            lt[w2][w1] = lt[w1][w2];
        }
        w = dijkstra(s, t);
        printf("Case #%d: ", casest-cases);
        if(w == INT_MAX) {
            printf("unreachable\n");
        } else {
            printf("%d\n", w);
        }
    }
    return 0;
}
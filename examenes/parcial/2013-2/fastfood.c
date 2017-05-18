#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXN 205
#define MAXK 35

int k, n;

int rst[MAXN];
int depots[MAXK];

int tds() {
    int i, sum = 0;
    for(i = 0; i < n; ++i) {
        sum += 
    }
}

int main() {
    int i, j, chain = 1;
    while(scanf("%d %d", &n, &k)) {
        if(n == 0 && k == 0) break;
        for(i = 0; i < n; ++i) {
             scanf("%d", &rst[i]);
        }
        printf("Chain %d\n", chain);
        for(i = 1; i <= n; ++i) {
            for(j = 0; j < k; ++j) {
                
            }
        }
        ++chain;
        for(i = 1; i <= k; ++i) {
            printf("Depot %d at restaurant serves restaurants\n", k);
        }
        printf("Total distance sum = \n");
    }
    return 0;
}
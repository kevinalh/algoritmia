#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1000

int max(int a, int b) {
    return a < b ? b : a;
}

int main() {
    int coins[MAXN];
    int i = 0, tmp;
    while(scanf("%d", &tmp)) {
        if(tmp < 0) break;
        coins[i] = tmp;
        ++i;
    }
    int n = i;
    int sol[MAXN];
    memset(sol, 0, MAXN*sizeof(int));
    sol[0] = coins[0];
    sol[1] = max(coins[0], coins[1]);
    for(i = 2; i < n; ++i) {
        sol[i] = max(coins[i] + sol[i-2], sol[i-1]);
    }
    printf("%d\n", sol[n-1]);
    return 0;
}

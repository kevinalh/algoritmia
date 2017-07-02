/* HackerRank
 * Similar Pair
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXN 100003

int n, k;
int g[MAXN];

int main() {
    scanf("%d %d", &n, &k);
    int i, j, tmp, tmp2;
    memset(g, 0, MAXN*sizeof(int));
    for(i = 1; i < n; ++i) {
        scanf("%d", &tmp);
        scanf("%d", &tmp2);
        g[tmp2] = tmp;
    }
    int sim = 0;
    for(i = 1; i <= n; ++i) {
        /* no parent */
        if(g[i] == 0) continue;
        /* look for all the parents */
        j = g[i];
        while(j != 0) {
            if(abs(i - j) <= k) ++sim;
            /* we go to the next parent */
            j = g[j];
        }
    }
    printf("%d\n", sim);
    return 0;
}

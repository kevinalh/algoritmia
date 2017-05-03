#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>

#define MAXN 350

int main() {
    double maxf = 5.21, cur;
    int i = 1, n = 0;
    double hang[MAXN];
    memset(hang, 0, MAXN*sizeof(double));
    hang[0] = 0.00;
    while(hang[n] <= maxf && n < MAXN) {
        ++n;
        hang[n] = hang[n-1] + (1.0)/(n+1);
    }
    while(scanf("%lf", &cur)) {
        if(cur <= DBL_EPSILON) break;
        for(i = 1; i <= n; ++i) {
            if(hang[i] >= cur) break;
        }
        printf("%d card(s)\n", i);
    }
    return 0;
}

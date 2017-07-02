#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 300005
long long ways[N];

int main() {
    int i, j;
    long long coins[12] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};
    long long hasta;
    ways[0] = 1;
    for(i = 0; i < 11; ++i) {
        hasta = N - coins[i];
        for(j = 0; j < hasta; ++j) {
            ways[j + coins[i]] += ways[j];
        }
    }
    double input;
    while(scanf("%lf", &input)) {
        if(input == 0) break;
        /* we add 0.5 for rounding issues */
        printf("%6.2lf%17lld\n", input, ways[(long long) (input*100+0.5)]);
    }
    return 0;
}
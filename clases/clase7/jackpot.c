/*
UVa
10684 - The Jackpot
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NMAX 10002

int n;
int a[NMAX];

int main() {
    int i;
    while(scanf("%d", &n) && n != 0) {
        int cur = 0;
        int max = 0;
        for(i = 0; i < n; ++i) {
            scanf("%d", &a);
            if(a >= 0) {
                cur += a;
            }
            else {
                max = max < cur ? cur : max;
                cur = 0;
            }
        }
        if(a >= 0) max = max < cur ? cur : max;
        if(max <= 0) {
            printf("Losing streak\n");
        }
        else {
            printf("The maximum winning streak is %d\n", max);
        }
    }
    return 0;
}
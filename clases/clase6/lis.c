#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100

int main() {
    int seq[MAXN];
    int n, i, j;
    scanf("%d", &n);
    for(i = 0; i < n; ++i) {
        scanf("%d", &seq[i]);
    }
    int lis[MAXN];
    memset(lis, 0, MAXN*sizeof(int));
    lis[0] = 1;
    for(i = 1; i < n; ++i) {
        for(j = 0; j < i; ++j) {
            if(seq[j] < seq[i] && lis[j]+1 > lis[i]) {
                lis[i] = lis[j]+1;
            }
        }
    }
    int max = 0;
    for(i = 0; i < n; ++i) {
        if(lis[i] > max) max = lis[i];
    }
    printf("Longest Increasing Subsequence: %d\n", max);
    return 0;
}

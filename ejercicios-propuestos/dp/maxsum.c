#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 101

int n, a[MAXN][MAXN], s[MAXN][MAXN];

int main() {
    scanf("%d", &n);
    int i, j;
    for(i = 0; i < n; ++i) {
        for(j = 0; j < n; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    for(i = 0; i < MAXN; ++i) {
        memset(s[i], 0, MAXN*sizeof(int));
    }
    /* s[i][j] is the maximum sum of the rectangles of size ixj */
    
    return 0;
}

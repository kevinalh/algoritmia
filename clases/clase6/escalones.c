#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1000

int main() {
    int n;
    scanf("%d", &n);
    int f[MAXN];
    memset(f, 0, MAXN*sizeof(int));
    int i;
    f[0] = 1;
    f[1] = 1;
    for(i = 2; i < n; ++i) {
        f[i] = f[i-1] + f[i-2];
    }
    printf("%d\n", f[n-1]);
}

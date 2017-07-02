#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define min(a, b) ((a) < (b)) ? (a) : (b)

#define MAXN 103

int n;
int clouds[MAXN];

int go(int c) {
    if(c == n-1) return 0;
    int a = INT_MAX - 1;
    if(c+2<n && clouds[c+2] != 1) {
        a = go(c+2) + 1;
    }
    else if (c+1<n && clouds[c+1] != 1) {
        a = go(c+1) + 1;
    }
    return a;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &clouds[i]);
    }
    int max = go(0);
    printf("%d\n", max);
    return 0;
}
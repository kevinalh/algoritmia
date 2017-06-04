#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1000

int a[MAXN];
int n;

void merge(int l, int h, int m) {
    int n1 = m-l+1;
    int n2 = h-m;
    
}

void mergesort(int l, int h) {
    int m = (l+h)/2;
    mergesort(l, m);
    mergesort(m+1,h);
    merge(l, h, m);
    return;
}

int main() {
    int i;
    scanf("%d", &n);
    for(i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    mergesort(0, n);
    for(i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
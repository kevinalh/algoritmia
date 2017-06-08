/*
CodeForces
702A - Maximum Increase
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    long long i, n, a, b, sz = 0, max = 0;
    scanf("%I64d", &n);
    b = 0;
    for(i = 0; i < n; ++i) {
        scanf("%I64d", &a);
        if(a > b) {
            ++sz;
        } else {
            max = max < sz ? sz : max;
            sz = 1;
        }
        b = a;
    }
    max = max < sz ? sz : max;
    printf("%I64d\n", max);
    return 0;
}
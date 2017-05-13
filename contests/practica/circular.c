#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    long long i, m, n, k, q;
    scanf("%lld %lld %lld", &n, &k, &q);
    long long a[n+1];
    for(i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
    }
    for(i = 0; i < q; ++i) {
        scanf("%lld", &m);
        printf("%lld\n", a[(((m-k)%n)+n)%n]);
    }
    return 0;
}

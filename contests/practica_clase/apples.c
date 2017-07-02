#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    long long i, j, s, t, a, b, m, n;
    scanf("%lld %lld", &s, &t);
    scanf("%lld %lld", &a, &b);
    scanf("%lld %lld", &m, &n);
    long long d, apples = 0, oranges = 0;
    /* apples */
    for(i = 0; i < m; ++i) {
        scanf("%lld", &d);
        if(a+d>=s && a+d<=t) {
            ++apples;
        }
    }
    /* oranges */
    for(i = 0; i < n; ++i) {
        scanf("%lld", &d);
        if(b+d<=t && b+d>=s) {
            ++oranges;
        }
    }
    printf("%lld\n%lld\n", apples, oranges);
    return 0;
}

/*
Codeforces
559B - Equivalent Strings
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NMAX 200001

char a[NMAX], b[NMAX];
long long len;

int eq(long long ini1, long long ini2, long long sz) {
    long long i;
    for(i = 0; i < sz; ++i) {
        if(a[ini1 + i] != b[ini2 + i]) break;
    }
    /* If the strings are the same */
    if(i == sz) return 1;
    /* Else, check the second and third conditions */
    /* Only if the length is divisible by 2 */
    if(sz % 2 != 0) return 0;
    long long nsz = sz/2;
    return (eq(ini1, ini2, nsz) && eq(ini1+nsz, ini2+nsz, nsz))
        || (eq(ini1+nsz, ini2, nsz) && eq(ini1, ini2+nsz, nsz));
}

int main() {
    fgets(a, NMAX, stdin);
    fgets(b, NMAX, stdin);
    len = strlen(a);
    a[len] = '\0';
    b[len] = '\0';
    --len;
    if(eq(0, 0, len)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}

/*
CodeForces
805A - Fake NP
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    long long l, r;
    scanf("%I64d %I64d", &l, &r);
    if(l != r) printf("2\n");
    else printf("%I64d\n", l);
    return 0;
}
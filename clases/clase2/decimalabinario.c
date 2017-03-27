#include <stdio.h>

void d2b(int);

int main() {
    int n;
    scanf("%d", &n);
    d2b(n);
    printf("\n");
    return 1;
}

void d2b(int n) {
    if(n==0) return;
    d2b(n/2);
    printf("%d", n%2);
}

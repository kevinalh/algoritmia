#include <stdio.h>

#define MAX 10

int max(int a, int b);
int recursiveMax(int n, int a[n]);

int main(void) {
    int n, i, a[MAX], maximo;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    maximo = recursiveMax(n, a);
    printf("El maximo es: %d\n", &maximo);
    return 0;
}

int recursiveMax(int n, int a[n]) {
    if (n==1) return a[n-1];
    return max(a[n-1], recursiveMax(n-1, a));
}

int max(int a, int b){
    return a > b ? a : b;
}

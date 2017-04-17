#include <stdio.h>
#include <math.h>
#include <limits.h>

int min(int a, int b, int c);
int max(int a, int b, int c);

int main() {
    int x, y, z, i, suma;
    scanf("%d %d %d", &x, &y, &z);
    int init = min(x,y,z);
    int fin = max(x,y,z);
    int minimo = INT_MAX;
    for(i = init; i <= fin; i++) {
        suma = abs(x-i) + abs(y-i) + abs(z-i);
        if(suma < minimo) {
            minimo = suma;
        }
    }
    printf("%d", minimo);
    return 0;
}

int min(int a, int b, int c) {
    int tmp = a < b ? a : b;
    return tmp < c ? tmp : c;
}

int max(int a, int b, int c) {
    int tmp = a > b ? a : b;
    return tmp > c ? tmp : c;
}

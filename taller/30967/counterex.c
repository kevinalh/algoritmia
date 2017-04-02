#include <stdio.h>

int coprimos(long long, long long);
long long gcd(long long, long long);
void ordenar(long long[], int);

int main() {
    long long l, r;
    long long i, j, k;
    long long numeros[3];
    scanf("%lld %lld", &l, &r);
    if(r-l < 2) {
        printf("-1\n");
        return 0;
    }
    for(i = l; i <= r; i++) {
        for(j = i+1; j <= r; j++) {
            for(k = j+1; k <= r; k++) {
                if(coprimos(i,j) && coprimos(j,k) && !coprimos(i,k)) {
                    numeros[0] = i;
                    numeros[1] = j;
                    numeros[2] = k;
                    ordenar(numeros, 3);
                    printf("%lld %lld %lld", numeros[0], numeros[1], numeros[2]);
                    return 0;
                }
            }
        }
    }
    printf("-1\n");
    return 0;
}

long long gcd(long long a, long long b) {
    long long c;
    while(b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int coprimos(long long a, long long b) {
    return gcd(a,b) == 1 ? 1 : 0;
}

void ordenar(long long numeros[], int n) {
    int i, j;
    long long tmp;
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(numeros[i] > numeros[j]) {
                tmp = numeros[j];
                numeros[j] = numeros[i];
                numeros[i] = tmp;
            }
        }
    }
    return;
}

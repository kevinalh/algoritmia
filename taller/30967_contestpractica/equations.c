#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000

int cumple(int a, int b, int n, int m);
int min(int n, int m);

int main() {
    int a, b, n, m, count = 0;
    scanf("%d %d", &n, &m);
    int cotaa = min(floor(sqrt(n)), m);
    int cotab = min(n,floor(sqrt(m)));
    for(a = 0; a <= cotaa; a++) {
        for(b = 0; b <= cotab; b++) {
            if (cumple(a, b, n, m)) count++;
        }
    }
    printf("%d\n", count);
    return 0;
}

int cumple(int a, int b, int n, int m) {
    if (a*a + b == n && a + b*b == m) return 1;
    else return 0;
}

int min(int n, int m) {
    return n < m ? n : m;
}

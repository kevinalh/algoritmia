#include <stdio.h>

int main() {
    int i, n, m, z;
    scanf("%d %d %d", &n, &m, &z);
    int minuto = n;
    int count = 0;
    while(minuto <= z) {
        if(minuto % m == 0) count++;
        minuto += n;
    }
    printf("%d\n", count);
    return 0;
}

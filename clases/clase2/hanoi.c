#include <stdio.h>

void hanoi(int n, int source, int aux, int target);

int main() {
    int n;
    scanf("%d", &n);
    hanoi(n, 1, 2, 3);
    return 0;
}

void hanoi(int n, int source, int aux, int target) {
    if(n == 1) {
        printf("%d -> %d\n", source, target);
        return;
    }
    hanoi(n-1, source, target, aux);
    hanoi(1, source, aux, target);
    hanoi(n-1, aux, source, target);
    return;
}

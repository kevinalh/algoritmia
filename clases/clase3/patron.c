#include <stdio.h>

void patron(int, int);

int main() {
    int nCasos, n, i;
    scanf("%d", &nCasos);
    while(nCasos > 0) {
        scanf("%d %d", &n, &i);
        patron(n, i);
        printf("\n");
        nCasos--;
    }
    return 0;
}

void patron(int n, int i) {
    int j;
    if (n > 0) {
        patron(n/2, i);
        for(j = 0; j < i; j++) {
            printf(" ");
        }
        for(j = 0; j < n; j++) {
            printf("*");
        }
        printf("\n");
        patron(n/2, i + n/2);
    }
    return;
}

#include <stdio.h>
#include <stdlib.h>

void patron(int n, int i);

int main() {
    int n, i;
    scanf("%d %d", &n, &i);
    patron(n, i);
    return (EXIT_SUCCESS);
}

void patron(int n, int i) {
    int j;
    if(n == 1) {
        for(j = 0; j < i; j++) {
            printf(" ");
        }
        printf("*\n");
        return;
    }
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

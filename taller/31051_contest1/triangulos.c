#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprimir(int a) {
    int i;
    for(i = 1; i <= a; i++) {
        printf("%d", a);
    }
    return;
}

int main(int argc, char** argv) {
    int n, i, amp, freq, j, k;
    scanf("%d", &n);
    getchar();
    for(i = 0; i < n; i++) {
        scanf("%d", &amp);
        scanf("%d", &freq);
        getchar();
        for(j = 0; j < freq; j++) {
            for(k = 1; k <= amp; k++) {
                imprimir(k);
                printf("\n");
            }
            for(k = amp-1; k >= 1; k--) {
                imprimir(k);
                printf("\n");
                
            }
            if(i != n-1 || j != freq-1) printf("\n");
        }
    }
    return (EXIT_SUCCESS);
}
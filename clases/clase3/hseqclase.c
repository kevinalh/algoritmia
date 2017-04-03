#include <stdio.h>
#include <stdlib.h>

int hseq(int ini, int fin, int seq[fin+1]);

int main() {
    int i, n;
    scanf("%d", &n);
    int seq[n];
    for(i = 0; i < n; i++) {
        scanf("%d", &seq[i]);
    }
    if(hseq(0, n-1, seq)) printf("Si es h-sequence\n");
    else printf("No es h-sequence\n");
    return 0;
}

int hseq(int ini, int fin, int seq[fin+1]) {
    int c;
    if(ini == fin) return (seq[fin] == 0);
    if(seq[ini] == 1) {
        for(c = ini + 1; c < fin; c++) {
            if(hseq(ini+1, c, seq) && hseq(c+1, fin, seq))
                return 1;
        }
    }
    return 0;
}

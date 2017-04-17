#include <stdio.h>
#include <stdlib.h>

#define MAX_K 14
#define SET 6

int main() {
    int k, i;
    int a, b, c, d, e, f;
    int num[MAX_K];
    int primera = 0;
    do {
        scanf("%d", &k);
        if(k == 0) break;
        for(i = 0; i < k; i++) {
            scanf("%d", &num[i]);
        }
        if(primera != 0) printf("\n");
        int limit = k + 1 - SET;
        for(a = 0; a < limit; a++) {
            for(b = a + 1; b < limit + 1; b++) {
                for(c = b + 1; c < limit + 2; c++) {
                    for(d = c + 1; d < limit + 3; d++) {
                        for(e = d + 1; e < limit + 4; e++) {
                            for(f = e + 1; f < limit + 5; f++) {
                                printf("%d %d %d %d %d %d", num[a], num[b], num[c], num[d], num[e], num[f]);
                                printf("\n");
                            }
                        }
                    }
                }
            }
        }
        primera = 1;
    } while(k != 0);
    return 0;
}

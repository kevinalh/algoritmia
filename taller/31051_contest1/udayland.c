#include <stdio.h>
#include <stdlib.h>

#define SPR 4

int main(int argc, char** argv) {
    int n;
    scanf("%d", &n);
    int i, j, k, l;
    char todo[1001][6];
    getchar();
    for(i = 0; i < n; i++) {
        fgets(todo[i], 7, stdin);
    }
    for(i = 0; i < n; i++) {
        for(j = 0; j < 4; j++) {
            if(todo[i][j] == 'O' && todo[i][j+1] == 'O') {
                printf("YES\n");
                todo[i][j] = '+';
                todo[i][j+1] = '+';
                for(k = 0; k < n; k++) {
                    for(l = 0; l < 5; l++) {
                        printf("%c", todo[k][l]);
                    }
                    printf("\n");
                }
                
                return 0;
            }
        }
    }
    printf("NO\n");
    return (EXIT_SUCCESS);
}


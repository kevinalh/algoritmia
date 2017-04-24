/* UVa 11283
 * Playing Boggle
 * */

#include <stdio.h>
#include <string.h>

#define M 101

int boggle(char grid[4][4], char words[M][18]);

int main() {
    int i, j, k, n, m, score;
    char grid[4][4];
    char words[M][18];
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        score = 0;
        getchar(); /* Blank line before each group */
        for(j = 0; j < 4; j++) {
            for(k = 0; k < 4; k++) {
                scanf("%c", &grid[i][j]);
            }
        }
        scanf("%d", &m);
        for(j = 0; j < m; j++) {
            fgets(words[j], 17, stdin);
        }
        printf("Score for Boggle game #%d: %d\n", i+1, score);
    }
    return 0;
}

int boggle(char grid[4][4], char words[M][18], int x, int y) {
    int i, j;
    for(i = -1; i <= 1; i++) {
        for(j = -1; j <= 1; j++) {
            if()
        }
    }
    return 0;
}

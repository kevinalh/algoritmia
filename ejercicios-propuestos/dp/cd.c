/* UVa
 * 624 - CD */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a,b) ((a) > (b) ? a : b)
#define MIN(a,b) ((a) < (b) ? a : b)

#define MAXN 22
#define MAXT 100

/* Knapsack 0/1 problem where value = weight */

int main() {
	char line[MAXN*2+6];
	int i, j, n, t, cd[MAXN], cont[MAXN];
	while(scanf("%d", &t) == 1) {
		/* t: minutes on tape
		 * n: amount of tracks in CD */
		scanf("%d", &n);
		for(i = 0; i < n; ++i) {
			scanf("%d", &cd[i]);
		}
		int s[MAXN][t+1];
		/* Using zero items, we can only get 0 minutes */
		memset(s[0], 0, (t+1)*sizeof(int));
		memset(cont, 0, MAXN*sizeof(int));
		for(i = 1; i <= n; ++i) {
			for(j = 0; j <= t; ++j) {
				/* if the i-th item has more minutes than allowable,
				 * we can't use it */
				if(cd[i-1] > j) {
					s[i][j] = s[i-1][j];
				}
				/* otherwise, we take the maximum between not using it and
				 * using it */
				else {
					s[i][j] = MAX(s[i-1][j], s[i-1][j-cd[i-1]]+cd[i-1]);
				}
			}
		}
		/* this is for knowing which items were added */
		/* probably there's a better solution */
		i = n;
		j = t;
		while(i > 0) {
			/* if the difference between the minutes considering until the i-th track
			 * and a maximum of j minutes, and the minutes considering until the (i-1)-th track
			 * and a maximum of j-cd[i-1] minutes is exactly cd[i-1], that means we used the
			 * i-th track*/
			if(s[i][j]-s[i-1][j-cd[i-1]] == cd[i-1]) {
				cont[i-1] = 1;
				j -= cd[i-1];
			}
			--i;
		}
		for(i = 0; i < n; ++i) {
			if(cont[i]) printf("%d ", cd[i]);
		}
		printf("sum:%d\n", s[n][t]);
	}
    return 0;
}

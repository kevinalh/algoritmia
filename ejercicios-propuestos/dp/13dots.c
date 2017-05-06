/* UVa
 * 10819 - Trouble of 13-Dots */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a,b) ((a) > (b) ? a : b)
#define MIN(a,b) ((a) < (b) ? a : b)

#define MAXN 102
#define MAXM 10002

int main() {
	int i, j, m, n;
	int p[MAXN];
	int f[MAXN];
	int s[MAXM];
	/* m: amount of pocket money
	 * n: number of items in the list */
	while(scanf("%d", &m) == 1) {
		scanf("%d", &n);
		for(i = 0; i < n; ++i) {
			scanf("%d %d", &p[i], &f[i]);
		}
		/* credit card refund */
		if(m >= 2000) m += 200;
		memset(s, 0, MAXM*sizeof(int));
		for(i = 1; i <= n; ++i) {
			for(j = m; j >= p[i-1]; --j) {
				s[j] = MAX(s[j], s[j-p[i-1]]+f[i-1]);
			}
		}
		/*
		memset(s[0], 0, MAXM*sizeof(int));
		for(i = 1; i <= n; ++i) {
			for(j = 0; j <= m; ++j) {
				if(p[i-1] > j) {
					s[i][j] = s[i-1][j];
				}
				else {
					s[i][j] = MAX(s[i-1][j], s[i-1][j-p[i-1]]+f[i-1]);
				}
			}
		}
		*/
		printf("%d\n", s[m]);
	}
	return 0;
}
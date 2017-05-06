/* UVa
 * 10306 - e-Coins */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a,b) ((a) > (b) ? a : b)
#define MIN(a,b) ((a) < (b) ? a : b)

#define MAXM 42

int main() {
	int i, j, p, n, m, s;
	int conv[MAXM], it[MAXM];
	scanf("%d", n);
	for(p = 0; p < n; ++p) {
		/* m: number of e-coin types
		 * s: value of e-modulus to be matched */
		scanf("%d %d", &m, &s);
		for(i = 0; i < m; ++i) {
			scanf("%d %d", &conv[i], &it[i]);
		}
	}
	return 0;
}
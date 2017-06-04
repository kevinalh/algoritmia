#include <stdio.h>
#include <stdlib.h>

#define N 102
#define MAXSUM 500*100 + 2

int coins[N];
int dp[N][MAXSUM];

int max(int a, int b){
	if(a > b) return a;
	else return b;
}

int main(){
	int t; scanf("%d",&t);
	int tc;
	int i,j,k;
	for(tc = 0; tc < t; tc++){
		int n; scanf("%d",&n);
		for(i = 1 ; i <= n ; i ++) scanf("%d",&coins[i]);
		int sum = 0;
		for(i = 1; i <= n ; i ++) sum+=coins[i];
		int mid = sum/2;
		for(i = 0; i<=n; i++) dp[i][0] = 1;
		for(i = 1; i<= n; i++){
			for(j = 1; j <= mid; j++){
				int ant = j-coins[i];
				if(ant < 0) dp[i][j] = dp[i-1][j];
				else dp[i][j] = max(dp[i-1][j],dp[i-1][ant]);
			}
		}
		int group1;
		for(j = mid; j>=0; j--){
			if(dp[n][j] == 1){
				group1 = j;
				break;
			}
		}
		int group2 = sum-group1;
		printf("%d\n",abs(group2 - group1));
	}
	return 0;
}
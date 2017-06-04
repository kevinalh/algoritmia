#include <stdio.h>
#include <stdlib.h>

#define N 100002

int arr[N];
int dp[N];

int main(){
	int n; scanf("%d",&n);
	for(int i = 0; i < n ; i ++){
		scanf("%d",&arr[i]);
		dp[i] = 1;
	}
	int tot = 0;
	for(int i = 1; i < n ; i ++){
		if(arr[i-1] < arr[i]) dp[i] = dp[i-1] + 1;
	}
	for(int i = 0; i < n; i ++){
		tot = (tot > dp[i] ? tot : dp[i]);
	}
	printf("%d\n",tot);
	return 0;
}
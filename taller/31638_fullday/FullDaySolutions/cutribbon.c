#include <stdio.h>
#include <stdlib.h>

int dp[4002];

int main(){
	int n,a,b,c; scanf("%d %d %d %d",&n, &a, &b, &c);
	int arr[3] = {a,b,c};
	for(int u = 1; u <= n; u++){
		for(int i = 0; i < 3; i++){
			int nuevo = u - arr[i];
			if(nuevo >= 0){
				int ant = (nuevo == 0 ? 1 : dp[nuevo]);
				if(ant == 0) continue;
				else{
					if(ant + 1 > dp[u]){
						dp[u] = ant + 1;
						if(nuevo == 0) dp[u]--;
					}
				}
			}
		}
	}
	printf("%d\n",dp[n]);
	return 0;
}
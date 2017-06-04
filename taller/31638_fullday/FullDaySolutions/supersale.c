#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int dp[1002][32]; //Matriz para la mochila
int n;
int v[1002]; //Valor de los objetos
int w[1002]; //Peso de los objetos
int ans[32]; //Guardara la respuesta para cada peso disponible

int max(int a, int b){
	return (a > b ? a : b);
}

void knapsack(){
	int i,j;
	for(i = 1; i <= n; i++){
		for(j = 1; j <= 30; j++){
			int ant = j-w[i];
			if(ant < 0) dp[i][j] = max(dp[i][j],dp[i-1][j]);
			else{
				dp[i][j] = max(dp[i][j],max(dp[i-1][j],dp[i-1][ant] + v[i]));
			}
		}

	}
}

int main(){
	int t; scanf("%d",&t);
	int tc,i,j;
	for(tc = 0; tc < t; tc++){
		scanf("%d",&n);
		for(i = 1; i <= n; i ++) scanf("%d %d",&v[i],&w[i]);
		for(i = 0; i <= n; i ++){
			for(j = 0; j<=30; j++) dp[i][j] = 0;
		}
		knapsack();
		for(j = 0; j <= 30; j++) ans[j] = dp[n][j];
		int q; scanf("%d",&q);
		int sum = 0;
		for(i = 0; i < q; i ++){
			int x;
			scanf("%d", &x);
			sum+=ans[x];
		}
		printf("%d\n",sum);
	}
	return 0;
}
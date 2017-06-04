#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define N 102

int mx[N][N];
int n,m;

int check(int pos){
	int u = 0, v = pos-1;
	while(u < v){
		for(int j = 0; j < m; j ++){
			if(mx[u][j] != mx[v][j]) return 0;
		}
		u++; v--;
	}
	return 1;
}

int go(int pos){
	if(pos%2 == 1) return pos;
	else{
		if(check(pos)) return go(pos/2);
		else return pos;
	}
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i = 0; i < n; i ++){
		for(int j = 0 ; j < m; j ++){
			scanf("%d",&mx[i][j]);
		}
	}
	int res = go(n);
	printf("%d\n",res);
	return 0;
}
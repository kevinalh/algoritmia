#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define N 52
#define EPS 1e-5

char mx[N][N];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int n,m; 

int ok(int r, int s){
	if(r < 0 || s < 0 || r>=n || s >=m) return 0;
	else return 1;
}


int dfs(int x, int y, char c, int px, int py){
	int ret = 0;
	mx[x][y] = c+32; //Este marcador nos indicara que antes de terminar todas las recursiones
				     //volver aqui significara un ciclo.
	for(int i = 0; i < 4; i ++){
		int r = x + dx[i], s = y + dy[i];
		if(!ok(r,s)) continue;
		if(mx[r][s] == c && !(r == px && s == py)){
			ret |= dfs(r,s,c,x,y);
		}
		else if(mx[r][s] == c+32 && !(r == px && s == py)) ret = 1;
	}
	mx[x][y] = '0';
	return ret;
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i = 0; i < n ; i ++){
		getchar();
		for(int j = 0 ; j < m; j ++){
			mx[i][j] = getchar();
		}
	}
	int ret = 0;
	for(char c = 'A'; c <='Z'; c ++){
		for(int i = 0; i < n ; i ++){
			for(int j = 0; j < m; j++){
				if(mx[i][j] == c) ret|=dfs(i,j,c,-1,-1);
			}
		}
	}
	ret ? printf("Yes\n") : printf("No\n"); //Ret es true? (es 1?) Si es que si, entonces imprimir yes, sino imprimir no
	return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define INF 1000000000

int col[1002][2];
int row[1002][2];
int mx[1002][1002];

int main(){
	int n,m; scanf("%d %d",&n,&m);
	for(int i = 0; i < n; i++){
		int mi = INF, ma = -1;
		for(int j = 0; j < m; j++){
			scanf("%d",&mx[i][j]);
			if(mx[i][j] == 1){
				if(j < mi) mi = j;
				if(j > ma) ma = j;
			}
		}
		row[i][0] = mi;
		row[i][1] = ma;
	}
	for(int j = 0; j < m; j++){
		int mi = INF, ma = -1;
		for(int i = 0; i < n; i++){
			if(mx[i][j] == 1){
				if(i < mi) mi = i;
				if(i > ma) ma = i;
			}
		}
		col[j][0] = mi;
		col[j][1] = ma;
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(mx[i][j]==0){
				if(j > row[i][0]) ans++;
				if(j < row[i][1]) ans++;
			}
		}
	}
	for(int j = 0; j < m; j++){
		for(int i = 0; i < n; i++){
			if(mx[i][j]==0){
				if(i > col[j][0]) ans++;
				if(i < col[j][1]) ans++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define N 102

char s[100002];
int v[1000002];
int n;

int go(int pos){
	if(pos >= n || pos < 0) return 1;
	else{
		if(s[pos] == 'X') return 0;
		int sig = (s[pos] == '>' ? 1: -1);
		s[pos] = 'X';
		return go(pos + sig*v[pos]);
	}
}

int main(){
	scanf("%d",&n);
	getchar();
	for(int i = 0; i < n; i ++) s[i] = getchar();
	getchar();
	for(int i = 0 ; i < n; i++) scanf("%d",&v[i]);

	if(go(0)) printf("FINITE\n");
	else printf("INFINITE\n");
	return 0;
}
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define N 102

int a[N];

int main(){
	int n; scanf("%d",&n);
	for(int i = 0 ; i < n ; i ++){
		if(i%4 < 2) printf("a");
		else printf("b");
	}
	printf("\n");
	return 0;
}
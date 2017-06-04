#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define N 102

int a[N];

int main(){
	int l,r; scanf("%d %d",&l,&r);
	if(l != r) printf("2\n");
	else printf("%d\n",l);
	return 0;

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define N 102

int a[N];

int main(){
	int n; scanf("%d",&n);
	int ret = -1;
	for(int i = 0 ; i < n ; i ++) scanf("%d",a + i);
	for(int i = 0 ; i < n ; i ++){
		for(int j = i ; j < n ; j++){
			int cnt = 0;
			for(int k = i; k <= j; k++) a[k] = 1 - a[k];
			for(int k = 0; k < n; k++) cnt+=a[k];
			for(int k = i; k <= j; k++) a[k] = 1 - a[k];
			ret = (cnt > ret ? cnt: ret);
		}
	}
	printf("%d\n",ret);
	return 0;
}
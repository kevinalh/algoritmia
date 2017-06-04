#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define N 100002

long long arr[N]; //Arreglo original
long long f[N]; //Este arreglo guarda la diferencia de valores absolutos consecutivos
long long g[N]; //Arreglo con signos cambiados desde la primera posicion
long long h[N]; //Arreglo con signos cambiados desde la segunda posicion

long long max(long long a, long long b){
	if(a > b) return a;
	else return b;
}

long long max_sum_subsequence(long long a[N], long long sz){
	long long ret = 0;
	long long cur = 0;
	for(long long i = 0 ; i < sz; i++){
		cur+=a[i];
		ret = max(cur,ret);
		if(cur < 0) cur = 0;
	}
	return ret;
}

int main(){
	long long n; scanf("%lld",&n);
	for(long long i = 0; i < n ; i ++) scanf("%lld",&arr[i]);
	for(long long i = 0; i < n-1; i ++) f[i] = abs(arr[i] - arr[i+1]);
	for(long long i = 0; i < n-1; i++){
		g[i] = f[i];
		if(i%2 == 1) g[i] = -g[i];
	}
	for(long long i = 1; i < n-1; i++){
		h[i-1] = f[i];
		if(i%2 == 0) h[i-1] = -h[i-1];
	}
	printf("%lld\n",max(max_sum_subsequence(g,n-1),max_sum_subsequence(h,n-2)));
	return 0;
}
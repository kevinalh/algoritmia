#include <stdio.h>
#include <stdlib.h>

#define N 10000001
#define MOD 1000000007

//A = 0, B = 1, C = 2, D = 3

int main(){
	long long n; scanf("%lld",&n);
	long long a = 1ll, b = 0ll, c = 0ll, d = 0ll;
	for(int i = 1; i <= n; i ++){
		long long bb = (a%MOD + c%MOD + d%MOD)%MOD;
		long long cc = (a%MOD + b%MOD + d%MOD)%MOD;
		long long dd = (a%MOD + b%MOD + c%MOD)%MOD;
		long long aa = (b%MOD + c%MOD + d%MOD)%MOD;
		d = dd; a = aa; b = bb; c = cc;
	}
	printf("%lld\n",a);
	return 0;
}
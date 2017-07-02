#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

#define MAXN 100002

char* solve(int n, int* a){
    int i, sl[MAXN], sr[MAXN];
    sl[0] = 0;
    sr[0] = 0;
    for(i = 1; i < n; ++i) {
        sl[i] = sl[i-1] + a[i-1];
        sr[i] = sr[i-1] + a[n-i];
    }
    for(i = 0; i < n; ++i) {
        if(sl[i] == sr[n-i-1]) {
            return "YES";
        }
    }
    return "NO";
}

int main() {
    int T; 
    scanf("%d", &T);
    for(int a0 = 0; a0 < T; a0++){
        int n; 
        scanf("%d", &n);
        int a[MAXN];
        for(int a_i = 0; a_i < n; a_i++){
           scanf("%d",&a[a_i]);
        }
        int result_size;
        char* result = solve(n, a);
        printf("%s\n", result);
    }
    return 0;
}

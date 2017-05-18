/*
LeetCode
53 - Maximum Subarray
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define NMAX 10000

long long arr[NMAX];
int sz;

typedef struct sba {
    int l;
    int h;
    long long value;
} sba;

sba maxsubmid(int low, int high, int mid) {
    int leftmax = INT_MIN;
    int left = mid;
    int sum = 0;
    int i;
    for(i = mid; i >= low; --i) {
        sum += arr[i];
        if(sum > leftmax) {
            leftmax = sum;
            left = i;
        }
    }
    int rightmax = INT_MIN;
    int right = mid+1;
    sum = 0;
    for(i = mid+1; i <= high; ++i) {
        sum += arr[i];
        if(sum > rightmax) {
            rightmax = sum;
            right = i;
        }
    }
    sba value;
    value.l = left;
    value.h = right;
    value.value = leftmax + rightmax;
    return value;
}

sba maxsub(int low, int high) {
    sba rmid;
    if(low == high) {
        rmid.l = low;
        rmid.h = high;
        rmid.value = arr[low];
        return rmid;
    }
    int mid = (high+low)/2;
    sba rleft, rright;
    rmid = maxsubmid(low, high, mid);
    rleft = maxsub(low, mid);
    rright = maxsub(mid+1, high);
    if(rleft.value >= rright.value && rleft.value >= rmid.value) {
        return rleft;
    }
    if(rright.value >= rleft.value && rright.value >= rmid.value) {
        return rright;
    }
    else return rmid;
}

int main() {
    sz = 0;
    while(scanf("%lld", &arr[sz])) {
        ++sz;
    }
    sba sol = maxsub(0, sz-1);
    printf("Left: %d\nRight: %d\nValue: %lld\n", sol.l, sol.h, sol.value);
    return 0;
}

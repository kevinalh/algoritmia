/*
LeetCode
53 - Maximum Subarray
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NMAX 10000

long long arr[NMAX];
long long sz;

int sub() {

}

int main() {
    sz = 0;
    while(scanf("%I64d", &arr[sz])) {
        ++sz;
    }
    
    return 0;
}
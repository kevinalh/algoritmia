#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return a < b ? b : a;
}

int min(int a, int b) {
    return a > b ? b : a;
}

int collatz(int a) {
    if(a == 1) return 1;
    if ((a % 2)==0){ 
        return 1+ collatz(a/2); 
    }
    else return 1+collatz(3*a + 1);
}

int main(int argc, char** argv) {
    int i, j, k, max2, tmp;
    while(scanf("%d %d", &i, &j) != EOF) {
        max2 = 0;
        for(k = min(i, j); k <= max(i, j); k++) {
            tmp = collatz(k);
            if(tmp > max2) max2 = tmp;
        }
        
        printf("%d %d %d\n", i,j,max2);
    } 
    return (EXIT_SUCCESS);
}


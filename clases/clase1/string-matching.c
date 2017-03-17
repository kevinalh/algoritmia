#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING 250

int main(int argc, char* argv[]) {
    int i, j;
    char* S = (char*) malloc(MAX_STRING*sizeof(char));
    char* K = (char*) malloc(MAX_STRING*sizeof(char));
    int m = strlen(S);
    int n = strlen(K);
    printf("S: ");
    gets(S, MAX_STRING, stdin);
    ntf("\nK: ");
    gets(K, MAX_STRING, stdin);
    for(i=0; i < n-m; i++) {
        for(j=0; j<m; j++){
            if(K[j] != S[i+j]) break;
            if(j==m-1) {
                printf("\nSe encontró K en el índice %d de S\n", i);
                return 0;
            }
        }
    }
    return 0;
}

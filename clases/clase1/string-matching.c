#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING 250

int main(int argc, char* argv[]) {
    int i, j;
    char* S = (char*) malloc(MAX_STRING*sizeof(char));
    char* K = (char*) malloc(MAX_STRING*sizeof(char));
    printf("S: ");
    fgets(S, MAX_STRING, stdin);
    printf("K: ");
    fgets(K, MAX_STRING, stdin);
    int n = strlen(S);
    int m = strlen(K);
    for(i=0; i < n-m; i++) {
        for(j=0; j<m; j++){
            if(K[j] != S[i+j]) break;
            if(j==m-2) {
                printf("Se encontró K en el índice %d de S\n", i);
                return 0;
            }
        }
    }
    printf("No se encontró la llave K en el texto S\n");
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

int esPalindromo(char cad[MAX], int i, int j);

int main() {
    char* cad = malloc(MAX*sizeof(char));
    fgets(cad, MAX, stdin);
    int palindromo = esPalindromo(cad, 0, strlen(cad));
    if(palindromo == 1)
        printf("Es palindromo\n");
    else
        printf("No es palindromo\n");
}

int esPalindromo(char cad[MAX], int i, int j){
    if(j <= i) return 1;
    if(cad[i] == cad[j]) {
        return esPalindromo(cad, i+1, j-1);
    }
    return 0;
}

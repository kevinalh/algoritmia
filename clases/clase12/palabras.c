#include <stdio.h>
#include <stdlib.h>

int main() {
    char* a = ["A", "FOOL", "AND", "HIS", "MONEY", "ARE", "SOON", "PARTED"];
    /* Hash: Sumar las posiciones en el alfabeto de las letras y calcular el resto de dividir entre 13 */
    int b[9];
    int i, sum;
    char* j;
    for(i = 0; i < 8; ++i) {
        j = a[i];
        sum = 0;
        while(*j != '\0') {
            sum += *j;
            j++;
        }
        b[i] = sum; 
        printf("%d ", sum);
    }
    printf("\n");
}

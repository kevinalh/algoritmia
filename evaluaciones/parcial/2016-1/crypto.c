#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXL 100
#define ABC 'Z'-'A'+1

char a[MAXL], b[MAXL], s[MAXL];
int al, bl, sl;
int letras[ABC+1];

int crypto(int col, int carry) {
    int i = -1, j = -1;
    if(a[al-col] != -1) goto a_definido;
    for(i = 0; i <= 9; ++i) {
        letras[a[al-col]] = i;
        a_definido:
        if(letras[b[bl-col]] != -1) goto b_definido; 
        for(j = 0; j <= 9; ++j) {
            letras[b[bl-col]] = j;
            b_definido:
            
            if(j == -1) break;
        }
        if(i == -1) break;
    }
    return 0;
}

int main() {
    int i;
    fgets(a, MAXL-1, stdin);
    fgets(b, MAXL-1, stdin);
    fgets(s, MAXL-1, stdin);
    al = strlen(a)-1;
    bl = strlen(b)-1;
    sl = strlen(s)-1;
    memset(letras, -1, (ABC+1)*sizeof(int));
    return 0;
}
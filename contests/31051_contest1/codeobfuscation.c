#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
    char S[501];
    fgets(S, 501, stdin);
    int i, j;
    int len = strlen(S)-1;
    if(S[0] == 'a' && len == 1) {
        printf("YES\n");
        return 0;
    }
    if(S[0] != 'a') {
        printf("NO\n");
        return 0;
    }
    for(i = 0; i < len; i++) {
        for(j = i+1; j < len; j++) {
            if(S[i] == S[j]) S[j] = '\0';
        }
    }
    
    for(i = 0; i < len; i++) {
        if(S[i] == '\0') continue; 
        for(j = i+1; j < len; j++) {
            if(S[j] == '\0') continue;
            else break;
            return 0;
        }
        if(j == len) {
            printf("YES\n");
            return 0;
        }
        if(S[j] != S[i] + 1) {
            printf("NO\n");
            return 0;
        }
        i = j-1;
    }
    printf("YES\n");
    return (EXIT_SUCCESS);
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100000

int main() {
    int i, j, ab=0, ba=0;
    char s[MAX];
    fgets(s, MAX, stdin);
    int length = strlen(s);
    char* key = "AB";
    if (length <= 4) {
        printf("NO");
        return 0;
    }
    for (i = 0; i < length-2; i++) {
        if (s[i] == key[0] && s[i+1] == key[1]) ab = 1;
        if (s[i] == key[1] && s[i+1] == key[0]) ba = 1;
        if (ab || ba) break;
    }
    if (ab || ba) {
        i++;
        if (s[i] == key[0] && s[i+1] == key[1]) {
            ab = 1;
            i++;
        }
        else if (s[i] == key[1] && s[i+1] == key[0]) {
            ba = 1;
            i++;
        }
        for (j = i+1; j < length-1; j++) {
            if (ba && s[j] == key[0] && s[j+1] == key[1]) {
                printf("YES\n");
                return 0;
            }
            if (ab && s[j] == key[1] && s[j+1] == key[0]) {
                printf("YES\n");
                return 0;
            }
        }
    }
    printf("NO\n");
    return 0;
}

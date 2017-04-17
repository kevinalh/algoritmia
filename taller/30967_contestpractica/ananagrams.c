#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1001
#define MAX_WORD_LENGTH 21
#define MAX_LINE 81

void pasarPalabras(int t, char* s, char[MAX_WORDS][MAX_WORD_LENGTH], int* n);
int related(char* s, char* t);
void ordenar(char* s, char* ordenado, int* length);
void swap(char* word, int a, int b);
void ordenarPalabras(int, char**);
void swap2(char** ananagrams, int a, int b);

int main() {
    int i, j, n = 0, m = 0;
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    char s[MAX_LINE];
    while(fgets(s, MAX_WORD_LENGTH*MAX_WORDS, stdin) != NULL) {
        if(!strcmp("#", s) || !strcmp("#\n", s) || !strcmp("#\0", s)) break;
        else pasarPalabras(strlen(s), s, words, &n);
    }
    int notananagrams[n];
    for(i = 0; i < n; i++) {
        notananagrams[i] = 0;
    }
    for(i = 0; i < n-1; i++) {
        if(notananagrams[i] == 1 || strlen(words[i]) == 1) continue;
        for(j = i+1; j < n; j++) {
            if(related(words[i], words[j])){
                notananagrams[j] = 1;
                notananagrams[i] = 1;
            }
        }
    }
    int howmany = 0;
    for(i = 0; i < n; i++) {
        howmany += notananagrams[i];
    }
    howmany = n - howmany;
    char* ananagrams[howmany];
    j = 0;
    for(i = 0; i < n; i++) {
        if (notananagrams[i] == 1) continue;
        else {
            ananagrams[j] = words[i];
            j++;
        }
    }
    ordenarPalabras(howmany, ananagrams);
    for(i = 0; i < howmany; i++) {
        printf("%s\n", ananagrams[i]);
    }
    return 0;
}

int related(char* s, char* t) {
    int length = strlen(s);
    if(length != strlen(t)) return 0;
    char ordenado[length];
    char ordenado2[length];
    ordenar(s, ordenado, &length);
    ordenar(t, ordenado2, &length);
    if(strcmp(ordenado, ordenado2) == 0) return 1;
    else return 0;
}

void ordenar(char* s, char* ordenado, int* length) {
    int i, j, min;
    for(i = 0; i < *length; i++) {
        ordenado[i] = tolower(s[i]);
    }
    for(i = 0; i < *length - 1; i++) {
        min = i;
        for(j = i+1; j < *length; j++) {
            if(ordenado[j] < ordenado[min]) {
                min = j;
            }
        }
        if(min != i) {
            swap(ordenado, i, min);
        }
    }
    ordenado[*length] = '\0';
    return;
}

void swap(char* word, int a, int b) {
    char tmp = word[a];
    word[a] = word[b];
    word[b] = tmp;
    return;
}

void swap2(char** ananagrams, int a, int b) {
    char* tmp = ananagrams[b];
    ananagrams[b] = ananagrams[a];
    ananagrams[a] = tmp;
    return;
}

void pasarPalabras(int t, char* s, char words[][MAX_WORD_LENGTH], int* n) {
    int i, j;
    char word[MAX_WORD_LENGTH];
    for(i = 0; i < t; i++) {
        if(isspace(s[i])) continue;
        else {
            for(j = i; j < t; j++) {
                if(isspace(s[j]) || s[j] == '\0') {
                    word[j - i] = '\0';
                    strcpy(words[*n], word);
                    (*n)++;
                    break;
                } else {
                    word[j - i] = s[j];
                }
            }
            i = j;
        }
    }
    return;
}

void ordenarPalabras(int n, char* ananagrams[n]) {
    int i = 0, j = 0;
    for(i = 0; i < n - 1; i++) {
        for(j = i+1; j < n; j++) {
            if(strcmp(ananagrams[i], ananagrams[j]) > 0) {
                swap2(ananagrams, i, j);
            }
        }
    }
    return;
}

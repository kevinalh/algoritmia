#include <stdio.h>
#include <stdlib.h>

#define NMAX 1000

typedef struct dragon {
    int str;
    int bonus;
} dragon;

void swap(dragon*, dragon*);
void ordenar(dragon*, int);

int main() {
    int i, n, s;
    dragon dragons[NMAX];
    scanf("%d %d", &s, &n);
    for(i = 0; i < n; i++) {
        scanf("%d %d", &dragons[i].str, &dragons[i].bonus);
    }
    ordenar(dragons, n);
    for(i = 0; i < n; i++) {
        if (s <= dragons[i].str) {
            printf("NO");
            return 0;
        } else {
            s += dragons[i].bonus;
        }
    }
    printf("YES");
    return 0;
}

void ordenar(dragon* dragons, int n) {
    int i, j, swapped;
    do {
        swapped = 0;
        for(i = 1; i < n; i++) {
            if(dragons[i-1].str > dragons[i].str) {
                swap(&dragons[i-1], &dragons[i]);
                swapped = 1;
            }
        }
    } while(swapped == 1);
    return;
}

void swap(dragon* dragon1, dragon* dragon2) {
    dragon tmp = *dragon1;
    *dragon1 = *dragon2;
    *dragon2 = tmp;
    return;
}

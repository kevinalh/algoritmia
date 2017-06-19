#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void invertir(list* lista) {
    node* ptr = lista->ini;
    node* next;
    while(ptr != NULL) {
        next = ptr->s;
        
        ptr = next;
    }
    return;
}

int main() {
    int i, n, tmp;
    scanf("%d", &n);
    list lista;
    crear(&lista);
    for(i = 0; i < n; ++i) {
        scanf("%d", &tmp);
        push(&lista, tmp);
    }
    imprimir(&lista);
    return 0;
}

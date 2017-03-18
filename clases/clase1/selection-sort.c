#include <stdio.h>
#include <stdlib.h>

void swap(int*, int, int);
void imprimir_lista(int*, int);

int main() {
    int i = 0;
    int j = 0;
    int n = 0;
    int* lista;
    printf("Cantidad de datos: ");
    scanf("%d", &n);
    lista = malloc(n*sizeof(int));
    for(i = 0; i < n; i++){
        scanf("%d", &lista[i]);
    }
    imprimir_lista(lista, n);
    int minimo = 0;
    int minimovalor = 0;
    for(i = 0; i < n; i++) {
        minimovalor = lista[i];
        minimo = i;
        for(j = i; j < n; j++) {
            if(lista[j] < minimovalor) {
                minimovalor = lista[j];
                minimo = j;
            }
        }
        swap(lista, i, minimo);
    }
    imprimir_lista(lista, n);
    return 0;
}

void swap(int* lista, int i, int j){
    int tmp = lista[i];
    lista[i] = lista[j];
    lista[j] = tmp;
    return;
}

void imprimir_lista(int* lista, int n){
    for(int i = 0; i < n; i++) {
        printf("%d\t", lista[i]);
    }
    printf("\n");
    return;
}

#include <stdio.h>
#include <stdlib.h>

/*
 * Hallar x1, ..., x6
 * sujetos a:
 * - horario(xi) intersectado con horario(xj) = vacio, i!=j
 * - 
 */

typedef struct conferencia{
    int codigo;
    int tipo;
    int inicio;
    int fin;
} conferencia;

int main(){
    int N = 0;
    int i, j;
    printf("Cantidad de conferencias y datos:\n");
    scanf("%d", &N);
    conferencia conf[N];
    for(i=0; i<N; i++){
        scanf("%d %d %d %d", &conf[i].codigo, &conf[i].tipo,
                &conf[i].inicio, &conf[i].fin);
    }
    int horas[24][4];
    return (EXIT_SUCCESS);
}


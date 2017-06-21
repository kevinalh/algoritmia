#include <stdlib.h>
#include <limits.h>

#include "grafo.h"

int dijkstra(TGrafo* g, TElemento e) {
    int n = g->numVertices;
    int* dist = malloc(n*sizeof(int));
    int* visitados = malloc(n*sizeof(int));
    int i;
    for(i = 0; i < n; ++i) {
        visitados[i] = 0;
        if(!Grafo_ExisteArista(g, e, i+1))
            dist[i] = INT_MAX;
    }
    for(i = 0; i < n; ++i) {
        int menorVertex = Grafo_ObtVerticeMin(dist, visitados, n);
        visitados[menorVertex] = 1;
        TVertice* vertice = Grafo_ExisteVertice(g, menorVertex + 1);
        TArista* arista = vertice->aristasInicio;
        while(arista) {
            int indVerticeAdyacente = arista->info - 1;
            int peso = arista->peso;
            if(visitados[indVerticeAdyacente] == 0 && dist[menorVertex] + peso < dist[indVerticeAdyacente]) {
                dist[indVerticeAdyacente] = dist[menorVertex] + peso;
            }
            arista = arista->sig;
        }
    }
    printf("Resultados\n");
    for(i = 0; i < n; ++i) {
        printf("%d\t", dist[i]);
    }
    printf("\n");
    return;
}

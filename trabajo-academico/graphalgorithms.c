#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <float.h>

#include "graph.h"
#include "graphalgorithms.h"
#include "queue.h"
#include "priority_queue.h"

#ifndef MAXSIZE

#define MAXSIZE 1420000

#endif

/**
* Devuelve un entero que corresponde con el elemento con mayor grado.
*/
int getDegreeErdos(TGraph* g) {
	int i, size = g->size, maxdeg = 0, currdeg = 0, k = 0;
	/* Buscamos linealmente el índice tal que el grado sea mayor */
	for (i = 0; i < size; ++i) {
		currdeg = graphVertexPointer(g, i)->degree;
		if (currdeg > maxdeg) {
			maxdeg = currdeg;
			k = i;
		}
	}
	return k;
}

/**
* Devuelve un entero que corresponde con el elemento con mayor PageRank.
*/
int getPageRankErdos(TGraph* g) {
	int i, size = g->size, k = 0;
	double maxpr = 0, currpr = 0;
	/* Buscamos linealmente el índice tal que el PageRank sea mayor */
	for (i = 0; i < size; ++i) {
		currpr = graphVertexPointer(g, i)->pagerank;
		if (currpr > maxpr) {
			maxpr = currpr;
			k = i;
		}
	}
	return k;
}

/**
* Devuelve un entero que corresponde con el elemento con mayor cercanía.
*/
int getClosenessErdos(TGraph* g) {
	int i, size = g->size, k = 0;
	double maxpr = 0, currpr = 0;
	/* Buscamos linealmente el índice tal que la cercanía sea mayor */
	for (i = 0; i < size; ++i) {
		currpr = graphVertexPointer(g, i)-> closeness;
		if (currpr > maxpr) {
			maxpr = currpr;
			k = i;
		}
	}
	return k;
}

/**
* Inicializa todos los vértices a un PageRank por defecto,
* de acuerdo con la opción seleccionada.
* - 1: Usando el degree.
* - 2: Usando closeness.
* - default: Usando la inversa de la cantidad de vértices.
*/
void graphInitializePageRank(TGraph* g, int option) {
	int size = g->size;
	int i;
	TVertex* v;
	for (i = 0; i < size; ++i) {
		v = graphVertexPointer(g, i);
		switch (option) {
		case 1:
			v->pagerank = (double) v->degree / g->nEdges;
			break;
		case 2:
			v->pagerank = (double) v->closeness;
		default:
			v->pagerank = 1 / g->size;
		}
	}
	return;
}

/**
* Computa la métrica de PageRank para todo el grafo, iterando una dada cantidad de veces.
*/
void computePageRankMetricIterative(TGraph* g, double alpha, int iniOption, int iterations) {
	graphInitializePageRank(g, iniOption);
	int i, size = g->size;
	while (iterations--) {
		for (i = 0; i < size; ++i) {
			computePageRankMetricVertex(g, i, alpha);
		}
	}
	return;
}

/**
* Computa la métrica de PageRank para todo el grafo, empleando un epsilon que da el
* criterio de convergencia. Retorna la cantidad de iteraciones tomadas.
*/
int computePageRankMetricEpsilon(TGraph* g, double alpha, int iniOption, int maxIterations, double eps) {
	graphInitializePageRank(g, iniOption);
	int i, size = g->size;
	int convergence = 1, it = 0;
	double lastPR, newPR, maxdiff, diff;
	do {
		convergence = 1;
		maxdiff = 0;
		for (i = 0; i < size; ++i) {
			lastPR = graphVertexPointer(g, i)->pagerank;
			newPR = computePageRankMetricVertex(g, i, alpha);
			/* Si la diferencia entre los PageRanks es mayor que el epsilon, no hay convergencia aún. */
			diff = fabs(newPR - lastPR);
			if (diff > maxdiff) maxdiff = diff;
		}
		++it;
		if (maxdiff > eps) convergence = 0;
		/* Para ver convergencia. */
		/* fprintf(stdout, "%d %.14lf\n", it, maxdiff); */
	} while (!convergence && it<maxIterations);
	return it;
}

/**
* Computa el nuevo PageRank para un vértice.
*/
double computePageRankMetricVertex(TGraph* g, int uindex, double alpha) {
	TVertex* u = graphVertexPointer(g, uindex);
	TVertex* v;
	TEdge* e = u->first;
	double pr = 0;
	while (e != NULL) {
		v = graphVertexPointer(g, e->index);
		pr += v->pagerank * (double) e->weight / (double) v->degree;
		e = e->next;
	}
	pr *= alpha;
	pr += (1 - alpha) / (double) g->size;
	u->pagerank = pr;
	return pr;
}

void dijkstra(TGraph* g, int root, double* dist) {
	int size = g->size , v; 
	for(int i = 0; i < size; ++i) dist[i] = DBL_MAX;
	dist[root] = 0; 
	HeapNode front;
	front.fst = 0;
	front.snd = root;
	TPriorityQueue pq;
	pqInitialize(&pq, MAXSIZE);
	pqPush(&pq, front);
	double d, def_weight;
	int u;
	TEdge* e;	
	while(!pqEmpty(&pq)) {
		front = pqTop(&pq); 
		d = front.fst;
		u = front.snd;
		if( d > dist[u] ) continue;
		e = graphVertexPointer(g, u)->first;
		while( e != NULL) {
			v = e -> index;
			def_weight = (1.0/(double)(e -> weight));
			if(dist[u] + def_weight < dist[v]) {
				dist[v] = dist[u] + def_weight;
				front.fst = dist[v];
				front.snd = v; 
				pqPush(&pq, front);
			}
		}
	}
}


/**
* Computa la métrica de cercanía para todos los vértices.
*/
void computeClosenessMetric(TGraph* g) {
	int i;
	printf("Closeness:\n");
	TVertex* v;
	double* dist = malloc(g->size * sizeof(double));
	for (i = 0; i < g->size; ++i) {
		v = graphVertexPointer(g, i);
		v->closeness = computeClosenessMetricVertex(g, i, dist);
		printf("%d: %.16lf\n", i, v->closeness);
	}
	free(dist);
	return;
}

double computeClosenessMetricVertex(TGraph* g, int uindex, double* dist) {
	double far = 0;
	dijkstra(g, uindex, dist);
	for(int i = 0; i < g->size; ++i){
		far += (1.0/(double)dist[i]) ;
		
	}
	return far;
}


bool graphIsConnected(TGraph* g) {
	TQueue q;
	queueInitialize(&q);
	bool* visited = (bool*)(malloc(g->size * sizeof(bool)));
	int i, j;
	visited[0] = 1;
	for (i = 1; i < g->size; ++i) {
		visited[i] = 0;
	}
	queueInsert(&q, 0);
	while (!queueIsEmpty(&q)) {
		i = queuePop(&q);
		TEdge* e = graphVertexPointer(g, i)->first;
		while (e != NULL) {
			j = e->index;
			if (!visited[j]) {
				visited[j] = 1;
				queueInsert(&q, j);
			}
			e = e->next;
		}
	}
	queueClean(&q);
	bool connected = 1;
	for (i = 0; i < g->size; ++i) {
		if (visited[i] == 0) {
			connected = 0;
			break;
		}
	}
	free(visited);
	return connected;
}

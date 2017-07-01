/*! \file */
#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <float.h>
#include <time.h>
#include <limits.h>

#include "graph.h"
#include "graphalgorithms.h"

#define MAXSIZE 1420000
#define MAXSTRING 60

char strings[MAXSIZE][MAXSTRING];
int ans1[MAXSIZE], ans2[MAXSIZE], ans3[MAXSIZE];
int erdos1[MAXSIZE], erdos2[MAXSIZE], erdos3[MAXSIZE];

void graphPrintMetrics(TGraph* g, FILE* fp, int type, int nthreads, int nerdos, int nrep, int proption, int exp);

/**
* Uso:
* ./cgmetrics nthreads type nerdos proption nrep < autoria.txt > graphoutput.txt
*
* nthreads: Cantidad de threads en paralelo a ejecutar (default = 1).
* type: 1: Calcula la métrica de cercanía usual. 2: La harmónica. 0: No calcula closeness (default = 1).
* nerdos: Cantidad de autores con mayor métrica a hallar en cada caso (default = 10).
* nrep: Cantidad de repeticiones de cada algoritmo, con fines de usar un tiempo promedio (default = 1).
* proption: Opción de inicialización de vértices en PageRank.
*	0: Inversa de |V|, 1: Degree, 2: Closeness (default = 0).
* exp: Exponente de epsilon = 10^-exp, usado para PageRank (default = 10).
* alpha: Factor amortiguador para PageRank, en formato dd -> 0.dd (default = 85).
*/
int main(int argc, char **argv) {
	TGraph g;
	int type = 1;
	int nthreads = 8;
	int nerdos = 10;
	int nrep = 1;
	int proption = 0;
	int exp = 10;
	if (argc == 1 || (argc == 2 && (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h")==0))) {
		printf("uso: cgmetrics nthreads [type] [nerdos] [proption] [nrep] [exp]\n\n");
		printf(" nthreads\tCantidad de threads en paralelo a ejecutar (default = 1).\n\n");
		printf(" type    \t1: Calcula la métrica de cercanía usual. 2: La harmónica. 0: No calcula closeness (default = 1).\n\n");
		printf(" nerdos  \tCantidad de autores con mayor métrica a hallar (default = 10).\n\n");
		printf(" nrep    \tCantidad de repeticiones de cada algoritmo (default = 1).\n\n");
		printf(" proption\tOpción de inicialización de vértices en PageRank (default = 0).\n\n");
		printf(" \t\t0 : Inversa de | V |\n \t\t1 : Degree\n \t\t2 : Closeness\n\n");
		printf(" exp     \tExponente de epsilon = 10^-exp, usado para PageRank (default = 10).\n\n");
		printf(" alpha   \tFactor amortiguador para PageRank, en formato dd -> 0.dd (default = 85)\n\n");
		return 0;
	}
	if (argc > 1) nthreads = strtol(argv[1], NULL, 10);
	if (argc > 2) type = strtol(argv[2], NULL, 10);
	if (argc > 3) nerdos = strtol(argv[3], NULL, 10);
	if (argc > 4) nrep = strtol(argv[4], NULL, 10);
	if (argc > 5) proption = strtol(argv[5], NULL, 10);
	if (argc > 5) exp = strtol(argv[6], NULL, 10);
	int cs, curr = 0;
	graphInitialize(&g, MAXSIZE);
	char *s, *t;
	char tmp1[MAXSTRING];
	char tmp2[MAXSTRING];
	/* Se pueden cambiar los valores fp y fp2 para tener una ubicación fija
	de los archivos */
	/*
	FILE* fp = fopen("L:/workspace/algoritmia/trabajo-academico/data/autoria.txt", "r");
	FILE* fp2 = fopen("L:/workspace/algoritmia/trabajo-academico/data/graphoutput.txt", "w");
	*/
	FILE* fp = stdin;
	FILE* fp2 = stdout;
	if (fp == NULL) reportError("File");
	fscanf(fp, "%d ", &cs);
	while (cs--) {
		fgets(tmp1, MAXSTRING - 1, fp);
		/* Insertamos lar aristas a ambos lados pues el grafo es
		no dirigido */
		if (!graphVertexExists(&g, tmp1)) {
			s = strings[curr++];
			strcpy(s, tmp1);
		}
		else {
			s = tmp1;
		}
		fgets(tmp2, MAXSTRING - 1, fp);
		if (!graphVertexExists(&g, tmp2)) {
			t = strings[curr++];
			strcpy(t, tmp2);
		}
		else {
			t = tmp2;
		}
		graphInsertEdge(&g, s, t);
	}
	/* Limpiamos la memoria del árbol pues ya no lo usaremos */
	graphCleanTree(g.tree.root);
	graphPrint(&g, fp2);
	/* Analizamos si el grafo es disconexo */
	int disconnected = graphIsDisconnected(&g, 0);
	if (disconnected == 0) {
		fprintf(fp2, "Connected graph\n");
	}
	else {
		fprintf(fp2, "Disconnected graph\n");
	}
	graphPrintMetrics(&g, fp2, type, nthreads, nerdos, nrep, proption, exp);
	graphCleanAll(&g);
	return 0;
}

void graphPrintMetrics(TGraph* g, FILE* fp, int type, int nthreads, int nerdos, int nrep, int proption, int exp) {
	int size = g->size;
	int i;
	double factor = (double) g->size - 1.0;
	double epsilon = 1;
	for (i = 0; i < exp; ++i) {
		epsilon *= 0.1;
	}
	fprintf(fp, "Threads: %d, Repetitions: %d, PR Option: %d, Eps: 10^-%d\n", nthreads, nrep, proption, exp);
	TVertex* v;
	/* Para obtener el tiempo de ejecución (CPU) */
	double seconds = 0;
	clock_t start;
	clock_t end;
	fprintf(fp, "____________________________\n");
	/* Erdos para degree */
	for (i = 0; i < nrep; ++i) {
		start = clock();
		computeDegreeMetric(g);
		end = clock();
		seconds += (double)(end - start) / CLOCKS_PER_SEC;
	}
	seconds = seconds / nrep;

	getDegreeErdos(g, erdos1);
	fprintf(fp, "Degree Erdos:\n> ");
	for (i = 0; i < nerdos; ++i) {
		fprintf(fp, "%d | %d %s", erdos1[i],
			graphVertexPointer(g, erdos1[i])->degree,
			graphStringFromVertex(g, erdos1[i]));
	}
	fprintf(fp, "Time: %.5lf s\n", seconds);
	fprintf(fp, "____________________________\n");
	/* Erdos para closeness */
	/**/
	if (type != 0) {
		seconds = 0;
		for (i = 0; i < nrep; ++i) {
			start = clock();
			computeClosenessMetricP(g, type, nthreads);
			end = clock();
			seconds += (double)(end - start) / CLOCKS_PER_SEC;
		}
		seconds = seconds / nrep;

		getClosenessErdos(g, erdos2);
		fprintf(fp, "Closeness Erdos:\n> ");
		for (i = 0; i < nerdos; ++i) {
			fprintf(fp, "%d | %.10lf %s", erdos2[i],
				graphVertexPointer(g, erdos2[i])->closeness * (g->size - 1),
				graphStringFromVertex(g, erdos2[i]));
		}
		fprintf(fp, "Time: %.5lf s\n", seconds);
		fprintf(fp, "____________________________\n");
	}
	/* Erdos para PageRank */
	seconds = 0;
	int it = 0;
	for (i = 0; i < nrep; ++i) {
		start = clock();
		it += computePageRankMetricEpsilon(g, 0.85, proption, 1000, epsilon);
		end = clock();
		seconds += (double)(end - start) / CLOCKS_PER_SEC;
	}
	seconds = seconds / nrep;
	it = it / nrep;

	getPageRankErdos(g, erdos3);
	fprintf(fp, "PageRank Erdos:\n> ");
	for (i = 0; i < nerdos; ++i) {
		fprintf(fp, "%d | %.10lf %s", erdos3[i],
			graphVertexPointer(g, erdos3[i])->pagerank * (g->size),
			graphStringFromVertex(g, erdos3[i]));
	}
	double totalpr = 0;
	for (i = 0; i < g->size; ++i) {
		totalpr += graphVertexPointer(g, i)->pagerank;
	}
	fprintf(fp, "Time: %.5lf s, Iterations: %d, Total: %.14lf\n", seconds, it, totalpr);
	fprintf(fp, "____________________________\n");
	/* Calculamos el numero de Erdos para cada uno */
	BFS(g, erdos1[0], ans1);
	BFS(g, erdos2[0], ans2);
	BFS(g, erdos3[0], ans3);
	/* Imprimimos toda la data */
	fprintf(fp, "__________________________________________________________________\n");
	fprintf(fp, "Degree\t\t\t\tCloseness (*|V|-1)\t\t\tPageRank (*|V|)\t\t\t(Erdos #)\n");
	fprintf(fp, "__________________________________________________________________\n\n");
	for (i = 0; i < size; ++i) {
		v = graphVertexPointer(g, i);
		fprintf(fp, "%d %s", i, v->value);
		fprintf(fp, "%d ", v->degree);
		if (ans1[i] < INT_MAX) {
			fprintf(fp, "(%d)", ans3[i]);
		}
		else {
			fprintf(fp, "(inf)");
		}
		fprintf(fp, "\t\t\t\t");
		/* Para la harmónica, los números son bastante grandes, por lo que no normalizamos como antes */
		if (type != 1) factor = 1.0;
		if (type != 0) {
			fprintf(fp, "%lf (%d)", (v->closeness)*factor, ans2[i]);
		}
		else {
			fprintf(fp, "-\t\t\t");
		}
		fprintf(fp, "\t\t\t\t");
		fprintf(fp, "%lf ", g->size * v->pagerank);
		if (ans3[i] < INT_MAX) {
			fprintf(fp, "(%d)", ans3[i]);
		}
		else {
			fprintf(fp, "(inf)");
		}
		fprintf(fp, "\n");
	}
	fprintf(fp, "\n");
	return;
}

#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <float.h>
#include <windows.h>
#include <limits.h>

#include "graph.h"
#include "graphalgorithms.h"

#define MAXSIZE 1420000
#define MAXSTRING 60
#define NREP 1
#define NERDOS 10

char strings[MAXSIZE][MAXSTRING];
int ans1[MAXSIZE], ans2[MAXSIZE], ans3[MAXSIZE];
int erdos1[MAXSIZE], erdos2[MAXSIZE], erdos3[MAXSIZE];

void graphPrintMetrics(TGraph*, FILE*);

int main() {
	TGraph g;
	int cs, curr = 0;
	graphInitialize(&g, MAXSIZE);
	char *s, *t;
	char tmp1[MAXSTRING];
	char tmp2[MAXSTRING];
	FILE* fp = fopen("L:/workspace/algoritmia/trabajo-academico/data/autoria.txt", "r");
	FILE* fp2 = fopen("L:/workspace/algoritmia/trabajo-academico/data/graphoutput.txt", "w");
	/*FILE* fp = fopen("~/autoria.txt", "r");
	FILE* fp2 = fopen("~/graphoutput.txt", "w");
	*/
	/*FILE* fp = stdin;
	FILE* fp2 = stdout;*/

	fscanf(fp, "%d ", &cs);
	while (cs--) {
		fgets(tmp1, MAXSTRING - 1, fp);
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
	graphCleanTree(g.tree.root);
	graphPrint(&g, fp2);
	int disconnected = graphIsDisconnected(&g, 0);
	if (disconnected == 0) {
		fprintf(fp2, "Connected graph\n");
	}
	else {
		fprintf(fp2, "Disconnected graph\n");
	}
	graphPrintMetrics(&g, fp2);
	return 0;
}

void graphPrintMetrics(TGraph* g, FILE* fp) {
	int size = g->size;
	int i;
	TVertex* v;
	/* Para obtener el tiempo de ejecución */
	LARGE_INTEGER frequency;
	LARGE_INTEGER start;
	LARGE_INTEGER end;
	QueryPerformanceFrequency(&frequency);
	double seconds = 0;
	fprintf(fp, "____________________________\n");
	/* Erdos para degree */
	for (i = 0; i < NREP; ++i) {
		QueryPerformanceCounter(&start);

		computeDegreeMetric(g);

		QueryPerformanceCounter(&end);
		seconds += (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
	}
	seconds = seconds / NREP;

	getDegreeErdos(g, erdos1);
	fprintf(fp, "Degree Erdos:\n> ");
	for (i = 0; i < NERDOS; ++i) {
		fprintf(fp, "%d %s", erdos1[i], graphStringFromVertex(g, erdos1[i]));
	}
	fprintf(fp, "Time: %lf s\n", seconds);
	fprintf(fp, "____________________________\n");
	/* Erdos para closeness */
	/**/
	seconds = 0;
	for (i = 0; i < NREP; ++i) {
		printf("%d\n", i);
		QueryPerformanceCounter(&start);

		computeClosenessMetricP(g, 2);

		QueryPerformanceCounter(&end);
		seconds += (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
	}
	seconds = seconds / NREP;

	getClosenessErdos(g, erdos2);
	fprintf(fp, "Closeness Erdos:\n> ");
	for (i = 0; i < NERDOS; ++i) {
		fprintf(fp, "%d %s", erdos2[i], graphStringFromVertex(g, erdos2[i]));
	}
	fprintf(fp, "Time: %lf s\n", seconds);
	fprintf(fp, "____________________________\n");

	/* Erdos para PageRank */
	seconds = 0;
	int it = 0;
	for (i = 0; i < NREP; ++i) {
		QueryPerformanceCounter(&start);

		it += computePageRankMetricEpsilon(g, 0.85, 1, 1000, 0.0000000001);

		QueryPerformanceCounter(&end);
		seconds += (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
	}
	seconds = seconds / NREP;
	it = it / NREP;

	getPageRankErdos(g, erdos3);
	fprintf(fp, "PageRank Erdos:\n> ");
	for (i = 0; i < NERDOS; ++i) {
		fprintf(fp, "%d %s", erdos3[i], graphStringFromVertex(g, erdos3[i]));
	}
	fprintf(fp, "Time: %lf s, Iterations: %d\n", seconds, it);
	fprintf(fp, "____________________________\n");
	/* Calculamos el numero de Erdos para cada uno */
	BFS(g, erdos1[0], ans1);
	BFS(g, erdos2[0], ans2);
	BFS(g, erdos3[0], ans3);
	/* Imprimimos toda la data */
	fprintf(fp, "__________________________________________________________________\n");
	fprintf(fp, "Degree\t\t\t\tCloseness (*10^4)\t\t\tPageRank (*10^4)\t\t\t(Erdos #)\n");
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
		/**/
		fprintf(fp, "%lf (%d)", v->closeness*10000.0, ans2[i]);

		/*fprintf(fp, "-\t\t\t");*/
		fprintf(fp, "\t\t\t\t");
		fprintf(fp, "%lf ", v->pagerank*10000.0);
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
#include <stdlib.h>  
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <float.h>
#include <windows.h>

#include "graph.h"
#include "graphalgorithms.h"

#define MAXSIZE 1420000
#define MAXSTRING 60

char strings[MAXSIZE][MAXSTRING];
int ans1[MAXSIZE], ans2[MAXSIZE], ans3[MAXSIZE];

void graphPrintMetrics(TGraph*, FILE*);

int main() {
    TGraph g;
    int cs, curr = 0;
    graphInitialize(&g, MAXSIZE);
	char *s, *t;
    char tmp1[MAXSTRING];
    char tmp2[MAXSTRING];
	FILE* fp = fopen("L:/workspace/algoritmia/trabajo-academico/data/autoria_10000.txt", "r");
	FILE* fp2 = fopen("L:/workspace/algoritmia/trabajo-academico/data/graphoutput.txt", "w");
	/*FILE* fp = stdin;
    FILE* fp2 = stdout;*/
    
	fscanf(fp, "%d ", &cs);
    while(cs--) {
        fgets(tmp1, MAXSTRING-1, fp);
        if(!graphVertexExists(&g, tmp1)) {
			s = strings[curr++];
            strcpy(s, tmp1);
        } else {
            s = tmp1;
        }
        fgets(tmp2, MAXSTRING-1, fp);
        if(!graphVertexExists(&g, tmp2)) {
			t = strings[curr++];
            strcpy(t, tmp2);
        } else {
            t = tmp2;
        }
        graphInsertEdge(&g, s, t);
	}
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
	double seconds;
	/* Erdos para degree */
	QueryPerformanceCounter(&start);

	computeDegreeMetric(g);

	QueryPerformanceCounter(&end);
	seconds = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

	int degErdos = getDegreeErdos(g);
	fprintf(fp, "Degree Erdos: %d %s", degErdos, graphStringFromVertex(g, degErdos));
	fprintf(fp, "Time: %lf s\n", seconds);
	/* Erdos para closeness */
	QueryPerformanceCounter(&start);

	computeClosenessMetric(g, 1);

	QueryPerformanceCounter(&end);
	seconds = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

	int clErdos = getClosenessErdos(g);
	fprintf(fp, "Closeness Erdos: %d %s", clErdos, graphStringFromVertex(g, clErdos));
	fprintf(fp, "Time: %lf s\n", seconds);
	/* Erdos para PageRank */
	QueryPerformanceCounter(&start);

	int it = computePageRankMetricEpsilon(g, 0.85, 1, 1000, 0.000000001);

	QueryPerformanceCounter(&end);
	seconds = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

	int prEpsErdos = getPageRankErdos(g);
	fprintf(fp, "PageRank Erdos: %d %s", prEpsErdos, graphStringFromVertex(g, prEpsErdos));
	fprintf(fp, "Time: %lf s, Iterations: %d\n", seconds, it);
	/* Calculamos el numero de Erdos para cada uno */
	BFS(g, degErdos, ans1);
	BFS(g, clErdos, ans2);
	BFS(g, prEpsErdos, ans3);
	/* Imprimimos toda la data */
	fprintf(fp, "__________________________________________________________________\n");
	fprintf(fp, "Degree\t\t\t\tCloseness (*10^4)\t\t\tPageRank (*10^4)\t\t\t(Erdos #)\n");
	fprintf(fp, "__________________________________________________________________\n\n");
	for (i = 0; i < size; ++i) {
		v = graphVertexPointer(g, i);
		fprintf(fp, "%d %s", i, v->value);
		fprintf(fp, "%d (%d)", v->degree, ans1[i]);
		fprintf(fp, "\t\t\t\t");
		fprintf(fp, "%lf (%d)", v->closeness*10000.0, ans2[i]);
		fprintf(fp, "\t\t\t\t");
		fprintf(fp, "%lf (%d)\n", v->pagerank*10000.0, ans3[i]);
	}
	return;
}

#include <stdlib.h>  
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <float.h>

#include "graph.h"
#include "graphalgorithms.h"

#define MAXSIZE 1420000
#define MAXSTRING 60

char strings[MAXSIZE][MAXSTRING];

void graphPrintMetrics(TGraph*, FILE*);

int main() {
    TGraph g;
    int cs, curr = 0;
    graphInitialize(&g, MAXSIZE);
	char *s, *t;
    char tmp1[MAXSTRING];
    char tmp2[MAXSTRING];
	FILE* fp = fopen("L:/workspace/algoritmia/trabajo-academico/data/demo1.txt", "r");
	FILE* fp2 = fopen("L:/workspace/algoritmia/trabajo-academico/data/graphoutput.txt", "w");
    /*
	FILE* fp = stdin;
    FILE* fp2 = stdout;
    */
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
	/*
	if (graphIsConnected(&g)) {
		printf("CONNECTED\n");
	}
	else printf("DISCONNECTED\n");
	*/
	graphPrintMetrics(&g, fp2);
	return 0;
}

void graphPrintMetrics(TGraph* g, FILE* fp) {
	int degErdos = getDegreeErdos(g);
	fprintf(fp, "Degree: %d %s\t%d\n", degErdos,
		graphStringFromVertex(g, degErdos),
		graphVertexPointer(g, degErdos)->degree);

	computeClosenessMetric(g);
	int clErdos = getClosenessErdos(g);
	fprintf(fp, "Closeness: %d %s\t%lf\n", clErdos,
		graphStringFromVertex(g, clErdos),
		graphVertexPointer(g, clErdos)->closeness);

	int it = computePageRankMetricEpsilon(g, 0.85, 1, 1000, 0.0000001);
	int prEpsErdos = getPageRankErdos(g);
	fprintf(fp, "PageRank (eps): %d %s\t%lf (%d it.)\n", prEpsErdos,
		graphStringFromVertex(g, prEpsErdos),
		graphVertexPointer(g, prEpsErdos)->pagerank, it);
	return;
}


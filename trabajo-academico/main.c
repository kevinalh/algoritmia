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
	FILE* fp = fopen("L:/workspace/algoritmia/trabajo-academico/data/autoria.txt", "r");
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
	fprintf(fp, "____________________________________________________\n");
	fprintf(fp, "Degree\t\tCloseness (*10^4)\t\tPageRank (*10^4)\n");
	fprintf(fp, "____________________________________________________\n\n");
	int size = g->size;
	int i;
	TVertex* v;	
	/* Erdos para degree */
	int degErdos = getDegreeErdos(g);
	/* Erdos para closeness */
	computeClosenessMetric(g, 2);
	int clErdos = getClosenessErdos(g);
	/* Erdos para PageRank */
	int it = computePageRankMetricEpsilon(g, 0.85, 1, 1000, 0.0000001);
	int prEpsErdos = getPageRankErdos(g);
	/* Imprimimos toda la data */
	for (i = 0; i < size; ++i) {
		v = graphVertexPointer(g, i);
		fprintf(fp, "%d %s%d\t\t\t\t%lf\t\t\t%lf\n", i, v->value, v->degree, v->closeness*10000.0, v->pagerank*10000.0);
	}
	return;
}


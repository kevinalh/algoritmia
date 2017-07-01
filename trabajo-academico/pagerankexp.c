/*! \file 
* Este programa se creó para poder generar rápidamente la Figura 2 del artículo.
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <float.h>
#include <time.h>
#include <windows.h>
#include <limits.h>

#include "graph.h"
#include "graphalgorithms.h"

#define MAXSIZE 1420000
#define MAXSTRING 60

char strings[MAXSIZE][MAXSTRING];
int ans1[MAXSIZE], ans2[MAXSIZE], ans3[MAXSIZE];
int erdos1[MAXSIZE], erdos2[MAXSIZE], erdos3[MAXSIZE];

double epsilonFromInt(int a);
void graphPrintPR(TGraph* g, FILE* fp);

int main(int argc, char **argv) {
	TGraph g;
	int type = 0;
	int nthreads = 8;
	int nerdos = 10;
	int nrep = 1;
	int proption = 0;
	int exp = 13;
	double alpha = 0.85;
	int cs, curr = 0;
	graphInitialize(&g, MAXSIZE);
	char *s, *t;
	char tmp1[MAXSTRING];
	char tmp2[MAXSTRING];
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
	graphPrintPR(&g, fp2);
	graphCleanAll(&g);
	return 0;
}

double epsilonFromInt(int a) {
	double epsilon = 1;
	int i;
	for (i = 0; i < a; ++i) {
		epsilon *= 0.1;
	}
	return epsilon;
}

void graphPrintPR(TGraph* g, FILE* fp) {
	int j, i, it = 0;
	fprintf(fp, "eps\t\ta\t\tit\n");
	double alpha = 0.80;
	int epsexp = 5;
	for (j = 0; j < 12; ++j) {
		alpha = 0.80;
		for (i = 0; i < 18; ++i) {
			fprintf(fp, "-%d\t\t%.2lf\t%d\n", epsexp, alpha, computePageRankMetricEpsilon(g, alpha, 0, 1000, epsilonFromInt(epsexp)));
			alpha += 0.01;
		}
		fprintf(fp, "\n");
		epsexp += 1;
	}
	return;
}

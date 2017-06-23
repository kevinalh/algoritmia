#include <stdbool.h>;

#include "graph.h"
#include "heap.h"

bool graphIsConnected(TGraph* g);
void dijkstra(TGraph* g, int sourceIndex, double* dist, THeap* priorityQueue);

/* Algoritmos para métricas de centralidad */
void graphInitializePageRank(TGraph* g, int option);
int getDegreeErdos(TGraph* g);
int getPageRankErdos(TGraph* g);
int getClosenessErdos(TGraph* g);
void computePageRankMetricIterative(TGraph*, double, int, int);
int computePageRankMetricEpsilon(TGraph* g, double alpha, int iniOption, int maxIterations, double eps);
double computePageRankMetricVertex(TGraph* g, int, double);
void computeClosenessMetric(TGraph* g);
double computeClosenessMetricVertex(TGraph* g, int uindex);
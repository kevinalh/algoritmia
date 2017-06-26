#include <stdbool.h>

#include "graph.h"
#include "heap.h"
#include "priority_queue.h"

int graphIsDisconnected(TGraph* g, int ref);
void dijkstra(TGraph* g, int root, double* dist, TPriorityQueue* pq);

/* Algoritmos para métricas de centralidad */
void graphInitializePageRank(TGraph* g, int option);
int getDegreeErdos(TGraph* g);
int getPageRankErdos(TGraph* g);
int getClosenessErdos(TGraph* g);
void computePageRankMetricIterative(TGraph*, double, int, int);
int computePageRankMetricEpsilon(TGraph* g, double alpha, int iniOption, int maxIterations, double eps);
double computePageRankMetricVertex(TGraph* g, int, double);
void computeClosenessMetric(TGraph* g, int type);
double computeClosenessMetricVertex(TGraph* g, int uindex, double* dist, TPriorityQueue* pq, int type);
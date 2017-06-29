#include <stdbool.h>

#include "graph.h"
#include "priority_queue.h"

int graphIsDisconnected(TGraph* g, int ref);
void dijkstra(TGraph* g, int root, double* dist, TPriorityQueue* pq);
void BFS(TGraph* g, int root, int* dist);

/* Algoritmos para métricas de centralidad */
void graphInitializePageRank(TGraph* g, int option);
void getDegreeErdos(TGraph* g, int* top);
void getPageRankErdos(TGraph* g, int* top);
void getClosenessErdos(TGraph* g, int* top);
void computeDegreeMetric(TGraph* g);
void computePageRankMetricIterative(TGraph*, double, int, int);
int computePageRankMetricEpsilon(TGraph* g, double alpha, int iniOption, int maxIterations, double eps);
double computePageRankMetricVertex(TGraph* g, int, double);
void computeClosenessMetric(TGraph* g, int type);
void computeClosenessMetricP(TGraph* g, int type);
double computeClosenessMetricVertex(TGraph* g, int uindex, double* dist, TPriorityQueue* pq, int type);
double computeClosenessMetricVertexP(TGraph* g, int uindex, double* dist, TPriorityQueue* pq, int type);
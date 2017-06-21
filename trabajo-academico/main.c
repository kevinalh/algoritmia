#include <stdlib.h>  
#include <stdio.h>
#include <string.h>

#include "graph.h"

#define MAXSIZE 1500000
#define MAXSTRING 100

int main() {
    TGraph g;
    int cs;
    graphInitialize(&g, MAXSIZE);
    char *s, *t;
    char tmp1[MAXSTRING];
    char tmp2[MAXSTRING];
	FILE* fp = fopen("L:/workspace/algoritmia/trabajo-academico/data/autoria.txt", "r");
	FILE* fp2 = fopen("L:/workspace/algoritmia/trabajo-academico/data/graphoutput.txt", "w");
    fscanf(fp, "%d ", &cs);
    while(cs--) {
        fgets(tmp1, MAXSTRING-1, fp);
        if(!graphVertexExists(&g, tmp1)) {
            s = malloc(MAXSTRING*sizeof(char));
            strcpy(s, tmp1);
        } else {
            s = tmp1;
        }
        fgets(tmp2, MAXSTRING-1, fp);
        if(!graphVertexExists(&g, tmp2)) {
            t = malloc(MAXSTRING*sizeof(char));
            strcpy(t, tmp2);
        } else {
            t = tmp2;
        }
        graphInsertEdge(&g, s, t);
    }
    graphPrint(&g, fp2);
    return 0;
}
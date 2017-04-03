Recursividad (parte 2)
======================

Patrón
------

Para poner varios casos, se usa `./patron < ../patron.in`, donde la primera línea da el número de casos y las siguientes dan los datos para cada una.

``` c
#include <stdio.h>

void patron(int, int);

int main() {
    int nCasos, n, i;
    scanf("%d", &nCasos);
    while(nCasos > 0) {
        scanf("%d %d", &n, &i);
        patron(n, i);
        printf("\n");
        nCasos--;
    }
    return 0;
}

void patron(int n, int i) {
    int j;
    if (n > 0) {
        patron(n/2, i);
        for(j = 0; j < i; j++) {
            printf(" ");
        }
        for(j = 0; j < n; j++) {
            printf("*");
        }
        printf("\n");
        patron(n/2, i + n/2);
    }
    return;
}
```

h-sequences
-----------

``` c
#include <stdio.h>
#include <stdlib.h>

int hseq(int ini, int fin, int seq[fin+1]);

int main() {
    int i, n;
    scanf("%d", &n);
    int seq[n];
    for(i = 0; i < n; i++) {
        scanf("%d", &seq[i]);
    }
    if(hseq(0, n-1, seq)) printf("Si es h-sequence\n");
    else printf("No es h-sequence\n");
    return 0;
}

int hseq(int ini, int fin, int seq[fin+1]) {
    int c;
    if(ini == fin) return (seq[fin] == 0);
    if(seq[ini] == 1) {
        for(c = ini + 1; c < fin; c++) {
            if(hseq(ini+1, c, seq) && hseq(c+1, fin, seq))
                return 1;
        }
    }
    return 0;
}
```

Backtracking
============

-   Consiste en hacer prueba y error.
-   Probamos alternativas, y si no funciona alguna, retrocedemos y probamos con la siguiente inmediata en el nivel anterior.
-   Proceso de búsqueda. El árbol de búsqueda crece rápidamente, por lo general de manera exponencial.

-   Cuando trabajamos con backtracking, hay que pensar en los estados. ¿Cuál es el estado a donde queremos llegar?
-   Luego pensamos cómo representar los estados.
-   Finalmente, pensamos en cómo representar los movimientos.

Knight's Tour
-------------

-   Dado un tablero n x n, un caballo se puede mover siguiente las reglas del ajedrez. Se empieza en la posición (x0, y0).
-   Se busca cubrir todo el tablero, si se puede.
-   Una solución posible es hacer una búsqueda en todos los recorridos posibles, pero esto es ineficiente.

-   Los movimientos y los estados son representados por matrices.
-   Cada fila de la matriz representa un movimiento, y cada columna la diferencia de las coordenadas.
-   Se borran los pasos que no conducen a la solución total.

``` c
#include <stdio.h>
#include <stdlib.h>

#define N 10
#define MAX_MOV 8

int MOV[MAX_MOV][2];

void imprimirMatriz(int A[N][N], int n);
void inicializarMatriz(int A[N][N], int n);
void inicializarMovimientos();
int es_valido(int A[N][N], int n, int x, int y);
int caballero(int A[N][N], int x, int y, int n, int nMov);

int main() {
    int n, x, y;
    scanf("%d", &n);
    scanf("%d %d", &x, &y);
    int tablero[n][n];
    inicializarMatriz(tablero, n);
    inicializarMovimientos();
    tablero[x][y] = 1;
    int res = caballero(tablero, x, y, n, 2);
    if(res)
        imprimirMatriz(tablero, n);
    else
        printf("No hay camino\n");
    return 0;
}

void imprimirMatriz(int A[N][N], int n) {
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    return;
}

void inicializarMatriz(int A[N][N], int n) {
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            A[i][j] = 0;
        }
    }
    return;
}

void inicializarMovimientos() {
    MOV[0][0] = 2; MOV[0][1] = 1;
    MOV[1][0] = 2; MOV[1][1] = -1;
    MOV[2][0] = 1; MOV[2][1] = 2;
    MOV[3][0] = 1; MOV[3][1] = -2;
    MOV[4][0] = -2; MOV[4][1] = 1;
    MOV[5][0] = -2; MOV[5][1] = -1;
    MOV[6][0] = -1; MOV[6][1] = 2;
    MOV[7][0] = -1; MOV[7][1] = -2;
}

int caballero(int A[N][N], int x, int y, int n, int nMov) {
    if (nMov == n*n + 1)
        return 1;
    int i;
    for(i = 0; i < MAX_MOV; i++){
        int newx = x + MOV[i][0];
        int newy = y + MOV[i][1];
        if(es_valido(A, n, newx, newy)) {
            A[newx][newy] = nMov;
            if(caballero(A, newx, newy, n, nMov+1))
                return 1;
            A[newx][newy] = 0; /* deshacer el cambio */
        }
    }
    return 0;
}

int es_valido(int A[N][N], int n, int x, int y) {
     if(x>=0 && x<n && y>=0 && y<n && A[x][y]==0)
         return 1;
     return 0;
}
```

Problema sencillo
-----------------

-   Tenemos las edades de todas las personas del mundo. Queremos calcular la moda de las edades.
-   Podemos tomar un arreglo de 120 entradas. Para cada persona, aumentamos uno a la casilla que contenga su edad.
-   Finalmente vamos linealmente en el arreglo para encontrar el más grande.

Tarea
-----

-   Resolver el problema del ciclo Hamiltoniano con backtracking (vino en un Parcial pasado).
-   Lo que se puede llevar al laboratorio es sólo manuscrito.
-   Hacer los ejercicios de las diapositivas: Sudoku, etc.


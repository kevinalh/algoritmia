---
title: Algoritmia - Clase 3
geometry: margin=3cm
date: 03 de abril
---
# Algoritmia - Clase 3

## Recursividad (parte 2)

### Patrón

Para poner varios casos, se usa `./patron < ../patron.in`, donde la primera línea da el número de casos y las siguientes dan los datos para cada una.

~~~{#patron .c}
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
~~~

### h-sequences

~~~{#hseqclase .c}
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
~~~

## Backtracking

- Consiste en hacer prueba y error.
- Probamos alternativas, y si no funciona alguna, retrocedemos y probamos con la siguiente inmediata en el nivel anterior.
- Proceso de búsqueda. El árbol de búsqueda crece rápidamente, por lo general de manera exponencial.

- Cuando trabajamos con backtracking, hay que pensar en los estados. ¿Cuál es el estado a donde queremos llegar?
- Luego pensamos cómo representar los estados.
- Finalmente, pensamos en cómo representar los movimientos.

### Knight's Tour

- Dado un tablero n x n, un caballo se puede mover siguiente las reglas del ajedrez. Se empieza en la posición (x0, y0).
- Se busca cubrir todo el tablero, si se puede.
- Una solución posible es hacer una búsqueda en todos los recorridos posibles, pero esto es ineficiente.

- Los movimientos y los estados son representados por matrices.
- Cada fila de la matriz representa un movimiento, y cada columna la diferencia de las coordenadas.
- Se borran los pasos que no conducen a la solución total.

~~~{#knight .c}
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
~~~

### Sudoku

~~~{#sudoku .c}
#include <stdio.h>
#include <stdlib.h>

#define N 9

int sudoku(int tabla[N][N], int x, int y);
int esValida(int tabla[N][N], int x, int y, int n);
void imprimirTabla(int tabla[N][N]);

int main() {
    int tabla[N][N];
    int i, j;
    /* Las casillas vacias deben tener un cero */
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            scanf("%d", &tabla[i][j]);
        }
    }
    if(sudoku(tabla, 0, 0)) {
        imprimirTabla(tabla);
    } else {
        printf("No se encontro solucion\n");
    }
    return 0;
}

int sudoku(int tabla[N][N], int x, int y) {
    if(x == N && y == N-1) {
        return 1;
    }
    if(x == N) {
        return sudoku(tabla, 0, y+1);
    }
    if(tabla[x][y] != 0) {
        return sudoku(tabla, x+1, y);
    }
    int n;
    for(n = 1; n <= N; n++) {
        /* Evaluamos si la opcion es valida */
        if(esValida(tabla, x, y, n)) {
            /* Modificamos el tablero */
            tabla[x][y] = n;
            if(sudoku(tabla, x+1, y)) {
                return 1;
            } else {
                tabla[x][y] = 0;
            }
        }
    }
    return 0;
}

int esValida(int tabla[N][N], int x, int y, int n) {
    int i, j;
    /* La fila y la columna no deben contener a n */
    for(i = 0; i < N; i++) {
        if(tabla[x][i] == n || tabla[i][y] == n) return 0;
    }
    /* Revisamos el cuadrante 3x3 */
    /* Hallamos la coordenada (x1, y1) donde empieza el cuadrado */
    int x1 = (x/3)*3;
    int y1 = (y/3)*3;
    for(i = x1; i < x1 + 3; i++) {
        for(j = y1; j < y1 + 3; j++) {
            if(tabla[i][j] == n) return 0;
        }
    }
    return 1;
}

void imprimirTabla(int tabla[N][N]) {
    int i, j, k;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", tabla[i][j]);
            if(j == 2 || j == 5) printf("| ");
        }
        if(i == 2 || i == 5) {
            printf("\n");
            for(k = 0; k < N+2; k++) {
                printf("--");
            }
        }
        printf("\n");
    }
}

~~~{#nqueens .c}
#include <stdio.h>
#include <stdlib.h>

#define N 20

int reinas(int tablero[N][N], int n, int dim);
void imprimirTablero(int tablero[N][N], int dim);
void inicializarTablero(int tablero[N][N], int dim);
int esValido(int tablero[N][N], int fila, int columna, int dim);

int main() {
    int n, dim;
    scanf("%d", &n);
    int tablero[N][N];
    inicializarTablero(tablero, n);
    if(reinas(tablero, 0, n)) {
        imprimirTablero(tablero, n);
    } else printf("No se encontro solucion\n");
    return 0;
}

int reinas(int tablero[N][N], int n, int dim) {
    if(n == dim) return 1;
    int i;
    /* Basta revisar sobre cada columna */
    for(i = 0; i < dim; i++) {
        if (esValido(tablero, i, n, dim)) {
            tablero[i][n] = 1;
            if(reinas(tablero, n+1, dim)) return 1;
            else tablero[i][n] = 0;
        }
    }
    return 0;
}

int esValido(int tablero[N][N], int fila, int columna, int dim) {
    int i, j;
    /* Basta revisar a la izquierda, pues no hay piezas a la derecha */
    /* Buscamos alguna reina en la fila */
    for(i = 0; i < columna; i++) {
        if(tablero[fila][i]) return 0;
    }
    /* Diagonal \ */
    for(i = fila, j = columna; i >= 0 && j >= 0; i--, j--) {
        if(tablero[i][j]) return 0;
    }
    /* Diagonal / */
    for(i = fila, j = columna; i < dim && j >= 0; i++, j--) {
        if(tablero[i][j]) return 0;
    }
    /* No es necesario revisar las columnas por construccion */
    return 1;
}

void imprimirTablero(int tablero[N][N], int dim) {
    int i, j;
    for(i = 0; i < dim; i++) {
        for(j = 0; j < dim; j++) {
            printf("%d ", tablero[i][j]);
        }
        printf("\n");
    }
    return;
}

void inicializarTablero(int tablero[N][N], int dim) {
    int i, j;
    for(i = 0; i < dim; i++) {
        for(j = 0; j < dim; j++) {
            tablero[i][j] = 0;
        }
    }
    return;
}~~~

### Problema sencillo

- Tenemos las edades de todas las personas del mundo. Queremos calcular la moda de las edades.
- Podemos tomar un arreglo de 120 entradas. Para cada persona, aumentamos uno a la casilla que contenga su edad.
- Finalmente vamos linealmente en el arreglo para encontrar el más grande.

## Tarea

- Resolver el problema del ciclo Hamiltoniano con backtracking (vino en un Parcial pasado).
- Lo que se puede llevar al laboratorio es sólo manuscrito.
- Hacer los ejercicios de las diapositivas: Sudoku, etc.

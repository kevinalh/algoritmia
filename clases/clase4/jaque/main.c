/*
 * Pregunta 1: Jaque al rey
 * 
 * Estrategia usada: Fuerza bruta.
 * Guardamos las posiciones y los tipos de pieza.
 * Para cada pieza, verificamos si es posible que llegue al rey.
 * Para esto, cada pieza tiene una forma diferente, la cual se detalla en
 * los comentarios de cada funcion.
 * Basta que una pieza pueda llegar para que este en jaque.
 */

/* 
 * Nombre: Kevin Languasco Huayaney
 * Codigo: 20132102
 * 
 * 8 de abril de 2017
 */

#include <stdio.h>
#include <stdlib.h>

#define NMAX 500000

int jaquetorre(int n, int torre, int x[NMAX], int y[NMAX], int reyx, int reyy);
int jaquealfil(int n, int alfil, int x[NMAX], int y[NMAX], int reyx, int reyy);
int jaquecaballo(int x, int y, int reyx, int reyy);

int main() {
    int i, j;
    char tipos[NMAX];
    int x[NMAX];
    int y[NMAX];
    int n;
    int reyx, reyy;
    int posible = 0;
    scanf("%d", &n);
    /* La pieza del rey es especial y se guarda por separado */
    scanf("%d %d", &reyx, &reyy);
    /* Iteramos para definir el tipo y la posición de las n piezas */
    for(i = 0; i < n; i++) {
        scanf("%c %d %d\n", &tipos[i], &x[i], &y[i]);
    }
    for(i = 0; i < n; i++) {
        if(tipos[i] == 'C' && jaquecaballo(x[i], y[i], reyx, reyy))
            posible = 1;
        else if(tipos[i] == 'T' && jaquetorre(n, i, x, y, reyx, reyy))
            posible = 1;
        else if(tipos[i] == 'A' && jaquealfil(n, i, x, y, reyx, reyy))
            posible = 1;
    }
    if(posible) printf("SI\n");
    else printf("NO\n");
    return (EXIT_SUCCESS);
}

int jaquetorre(int n, int torre, int x[NMAX], int y[NMAX], int reyx, int reyy) {
    /*
     * (x1, y1) es la posicion de la torre actual.
     * Basta verificar que el rey se encuentra en la misma columna y no hay
     * piezas en medio, y lo mismo para la verificacion horizontal con filas.
     */
    int i, j;
    int x1 = x[torre];
    int y1 = y[torre];
    /* Verticalmente */
    if(reyx == x1) {
        /* El rey esta encima de la torre */
        if(reyy > y1) {
            for(i = 0; i < n; i++) {
                if (i == torre || x[i] != x1) continue;
                /* Si la pieza esta en medio de la torre y el rey, es imposible
                 llegar */
                if(y[i] > y1 && y[i] < reyy) return 0;
            }
            /* Si ninguna pieza se puso en medio, se puede llegar */
            return 1;
        }
        /* El rey esta abajo de la torre */
        else if(reyy < y1) {
            for(i = 0; i < n; i++) {
                if (i == torre || x[i] != x1) continue;
                if(y[i] < y1 && y[i] > reyy) return 0;
            }
            return 1;
        }
    }
    /* Horizontalmente */
    else if (reyy == y1) {
        /* El rey esta a la derecha */
        if(reyx > x1) {
            for(i = 0; i < n; i++) {
                if (i == torre || y[i] != y1) continue;
                if(x[i] > x1 && x[i] < reyx) return 0;
            }
            return 1;
        }
        /* El rey esta a la izquierda */
        else if(reyx < x1) {
            for(i = 0; i < n; i++) {
                if (i == torre || y[i] != y1) continue;
                if(x[i] < x1 && x[i] > reyx) return 0;
            }
            return 1;
        }
    }
    return 0;
}

int jaquecaballo(int x, int y, int reyx, int reyy) {
    /* Buscamos en cada casilla posible del caballo,
     * si esta el rey, ya esta, pues el caballo salta encima de las piezas.
     */
    if((reyx == x+1 && reyy == y+2) ||
            (reyx == x+2 && reyy == y+1) ||
            (reyx == x+2 && reyy == y-1) ||
            (reyx == x+1 && reyy == y-2) ||
            (reyx == x-1 && reyy == y+2) ||
            (reyx == x-2 && reyy == y+1) ||
            (reyx == x-2 && reyy == y-1) ||
            (reyx == x-1 && reyy == y-2))
        return 1;
    else return 0;
}

int jaquealfil(int n, int alfil, int x[NMAX], int y[NMAX], int reyx, int reyy) {
    /*
     * Parecido al de la torre, pero hay que verificar de forma diagonal
     * en lugar de vertical u horizontal.
     * Usamos la ecuacion de la recta y - y1 = x - x1.
     * Si el rey cumple la ecuacion, se puede llegar en teoria. Para que de verdad
     * se pueda llegar, se tiene que revisar pieza por pieza si cumplen
     * la ecuacion (y tambien si esta a la derecha o izquierda)
     */
    int i, j;
    int x1 = x[alfil];
    int y1 = y[alfil];
    if(reyy - y1 == reyx - x1) {
        /* Si esta en la recta "/" */
        for(i = 0; i < n; i++) {
            if(y[i] - y1 == x[i] - x1) {
                /* Revisamos si esta en la parte de la recta donde
                 * puede fastidiar
                 */
                if(x1 < reyx && x[i] > x1 && x[i] < reyx)
                    return 0;
                else if(x1 > reyx && x[i] < x1 && x[i] > reyx)
                    return 0;
            }
        }
        return 1;
    }
    else if(reyy - y1 == x1 - reyx) {
        /* Si esta en la recta "\" */
        for(i = 0; i < n; i++) {
            if(y[i] - y1 == x1 - x[i]) {
                if(x1 < reyx && x[i] > x1 && x[i] < reyx)
                    return 0;
                else if(x1 > reyx && x[i] < x1 && x[i] > reyx)
                    return 0;
            }
        }
        return 1;
    }
    return 1;
}

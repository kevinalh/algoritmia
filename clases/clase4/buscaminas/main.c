/*
 * Pregunta 2: Buscaminas recursivo
 * 
 * Estrategia usada: Recursion
 * Usamos la funcion buscaminas para, en primer lugar, ver
 * las posiciones posibles alrededor (que no salgan fuera del tablero).
 * Luego, se cuenta la cantidad de bombas en las casillas posibles alrededor.
 * En caso de no tener bombas alrededor, se procede recursivamente en cada una
 * de las casillas.
 * Caso contrario, se marca el numero de bombas en la casilla.
 */

/* 
 * Nombre: Kevin Languasco Huayaney
 * Codigo: 20132102
 * 
 * 8 de abril de 2017
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void buscaminas(int m, int n, char matriz[m][n], int x, int y);
void imprimir(int m, int n, char matriz[m][n]);
char anumero(int n);

int main(int argc, char** argv) {
    int casos;
    scanf("%d", &casos);
    int i, j, k, m, n, x, y;
    for(k = 0; k < casos; k++) {
        /* Lectura */
        scanf("%d %d", &x, &y);
        scanf("%d %d", &m, &n);
        char matriz[m+1][n+1];
        char* aux = malloc((n+1)*sizeof(char));
        for(i = 0; i < m; i++) {
            getchar();
            fgets(aux, n+1, stdin);
            for(j = 0; j < n; j++) {
                matriz[i][j] = aux[j];
            }
        }
        /* Modifica la matriz usando la funcion buscaminas */
        buscaminas(m, n, matriz, x, y);
        /* Imprime la matriz resultante */
        imprimir(m, n, matriz);
    }
    return (EXIT_SUCCESS);
}

void buscaminas(int m, int n, char matriz[m][n], int x, int y) {
    /*
     * La matriz "posibles" guarda las posiciones a las cuales se puede ir,
     * para evitar repeticiones. Va en el siguiente orden:
     * 0 1 2
     * 3   4
     * 5 6 7
     */
    int cont = 0, i = 0, j = 0;
    if(matriz[x][y] == 'X')  {
        printf("Moriste\n");
        return;
    }
    if(matriz[x][y] == 'V') {
        int posibles[8][3];
        /*
         * Para cada i, posibles[i][0] es interpretado como un booleano: Si es
         * posible ir, en el sentido de no estar fuera del tablero, es 1, caso
         * contrario, es cero. Las siguientes entradas, posibles[i][1],
         * posibles[i][2] son las coordenadas x, y de la matriz en la dirección
         * indicada.
         */
        for(i = 0; i < 8; i++) {
            for(j = 0; j < 3; j++) {
                posibles[i][j] = 0;
            }
        }
        if(x-1 >= 0) {
            posibles[3][1] = x-1;
            posibles[3][2] = y;
            posibles[3][0] = 1;
        }
        if(x+1 < n) {
            posibles[4][1] = x+1;
            posibles[4][2] = y;
            posibles[4][0] = 1;
        }
        if(y-1 >= 0) {
            posibles[1][1] = x;
            posibles[1][2] = y-1;
            posibles[1][0] = 1;
        }
        if(y+1 < m) {
            posibles[6][1] = y+1;
            posibles[6][2] = x;
            posibles[6][0] = 1;
        }
        if(x+1 < n && y-1 >= 0) { 
            posibles[2][1] = x+1;
            posibles[2][2] = y-1;
            posibles[2][0] = 1;
        }
        if(x+1 < n && y+1 < m) { 
            posibles[7][1] = x+1;
            posibles[7][2] = y+1;
            posibles[7][0] = 1;
        }
        if(x-1 >= 0 && y-1 >= 0) { 
            posibles[0][1] = x-1;
            posibles[0][2] = y-1;
            posibles[0][0] = 1;
        }
        if(x-1 >= 0 && y+1 < m) { 
            posibles[5][1] = x-1;
            posibles[5][2] = y+1;
            posibles[5][0] = 1;
        }
        /*
         * Contamos las posiciones donde esta la X alrededor, en las posiciones
         * posibles.
         */
        for(i = 0; i < 8; i++) {
            if(posibles[i][0] == 0) {
                continue;
            }
            else if(matriz[posibles[i][1]][posibles[i][2]] == 'X') {
                cont++;
            }
        }
        /*
         * Si no encontramos bombas alrededor, procedemos recursivamente en cada
         * direccion.
         */
        if (cont == 0) {
            matriz[x][y] = '0';
            for(i = 0; i < 8; i++) {
                if(posibles[i][0] && matriz[posibles[i][1]][posibles[i][2]] == 'V') {
                    buscaminas(m, n, matriz, posibles[i][1], posibles[i][2]);
                }
            }
        } else {
            /*
             * Caso contrario, marcamos la celda con el numero de bombas.
             */
            matriz[x][y] = anumero(cont);
        }
    }
}

char anumero(int n) {
    if(n == 1) return '1';
    if(n == 2) return '2';
    if(n == 3) return '3';
    if(n == 4) return '4';
    if(n == 5) return '5';
    if(n == 6) return '6';
    if(n == 7) return '7';
    if(n == 8) return '8';
    if(n == 9) return '9';
    return '0';
}

void imprimir(int m, int n, char matriz[m][n]) {
    /*
     * Para imprimir matrices.
     */
    int i, j;
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
}
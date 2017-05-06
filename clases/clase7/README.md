Algoritmia - Clase 7
====================

LIS (continuación)
------------------

-   Consideremos el problema de dar el tamaño del LIS y la secuencia. Este se puede resolver haciendo las siguientes modificaciones.

``` c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100

int main() {
    int seq[MAXN];
    int n, i, j;
    scanf("%d", &n);
    for(i = 0; i < n; ++i) {
        scanf("%d", &seq[i]);
    }
    int lis[MAXN];
    lis[0] = 1;
    int max = 0;
    for(i = 1; i < n; ++i) {
        lis[i] = 1;
            if(seq[j] < seq[i] && lis[j]+1 > lis[i]) {
                lis[i] = lis[j]+1;
            }
        }
        if(lis[i] > max) {
            max = lis[i];
        }
    }
    printf("Longest Increasing Subsequence: %d\n", max);
    return 0;
}
```

Knapsack Problem
----------------

-   Dados n elementos con pesos enteros y valores, y una mochila de capacidad entera W, debemos encontrar el subconjunto más valioso de elementos que caben en la mochila.

``` c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXW 100
#define MAXN 100

int max(int a, int b);
int mochila(int w[MAXN+1], int v[MAXN+1], int W, int N);

int main() {
    int i, j, N, W;
    scanf("%d", &N);
    scanf("%d", &W);
    int w[MAXN+1];
    int v [MAXN+1];
    for(i = 0; i < N; ++i) {
        
    }
    int valor = mochila(w, v, W, N);
    printf("Valor maximo: %d\n", valor);
    return 0;
}

int mochila(int w[MAXN+1], int v[MAXN+1], int W, int N) {
    int dp[MAXN+1][MAXW+1] = {{}};
    int i, j;
    for(i = 1; i <= N; ++i) {
        for(j = 1; j <= W; ++j) {
            if(w[i-1] > j) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(v[i-1] + dp[i-1][j-w[i-1]], dp[i-1][j]);
            }
        }
    }
    return dp[N][W];
}

int max(int a, int b) {
    return a > b ? a : b;
}
```

Laboratorio 3 del 2015-2
------------------------

-   Tablero de tamaño MxN con una cierta cantidad de dinero en cada casilla.
-   Si se escoge una casilla, todo el dinero en las filas superior e inferior se vacían, así como la de la izquierda y de la derecha.
-   Se debe escoger dinero hasta que todo se anule, maximizando el valor.

-   La idea es resolver Coin Row en las dos direcciones, usando un arreglo auxiliar para guardar los máximos de cada fila.

``` c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    return 0;
}
```

Tarea
-----

-   Tarea: Implementar este problema, y el LIS modificado.
-   El problema de Supersale (uVA 1071) y Jackpot (uVA 10684).
-   Problema de Edit Distance: ¿Cuál es el número mínimo de movimientos para transformar una palabra a otra palabra?. Las operaciones son: Insertar, Eliminar y Reemplazar letra. Por ejemplo: Para brota -&gt; rota, sólo se necesita eliminar una letra. En Sunday -&gt; Saturday, serían 3 movimientos, un reemplazo y dos inserciones. Algoritmo de Levenshtein. La idea es que, antes teníamos dos operaciones: Agregar y no agregar. Acá tenemos tres operaciones, y queremos minimizar la distancia. Generamos una matriz donde una palabra es la origen (las filas), y la otra es el destino (las columnas).


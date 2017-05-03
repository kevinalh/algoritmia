Algoritmia - Clase 6
====================

Programación Dinámica
---------------------

### Escalones

-   Hallar todas las formas posibles para llegar al n-ésimo escalón.
-   Una forma básica es hacer recursivamente una sucesión de Fibonacci.
-   Sin embargo, podemos reducir la complejidad del problema a 𝒪(*n*) guardando las soluciones para su uso posterior.

``` c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1000

int main() {
    int n;
    scanf("%d", &n);
    int f[MAXN];
    memset(f, 0, MAXN*sizeof(int));
    int i;
    f[0] = 1;
    f[1] = 1;
    for(i = 2; i < n; ++i) {
        f[i] = f[i-1] + f[i-2];
    }
    printf("%d\n", f[n-1]);
}
```

### Hangover

-   En programación dinámica normalmente se usa una tabla de resultados conocidos, a partir de las cuales llenamos instancias más complejas.
-   [Hangover](http://poj.org/problem?id=1003) es un problema que se puede resolver siguiendo este principio

``` c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>

#define MAXN 350

int main() {
    double maxf = 5.21, cur;
    int i = 1, n = 0;
    double hang[MAXN];
    memset(hang, 0, MAXN*sizeof(double));
    hang[0] = 0.00;
    while(hang[n] <= maxf && n < MAXN) {
        ++n;
        hang[n] = hang[n-1] + (1.0)/(n+1);
    }
    while(scanf("%lf", &cur)) {
        if(cur <= DBL_EPSILON) break;
        for(i = 1; i <= n; ++i) {
            if(hang[i] >= cur) break;
        }
        printf("%d card(s)\n", i);
    }
    return 0;
}
```

### Coin Row

-   **Principio de optimalidad**: Se busca la solución óptima en los subproblemas, para luego usarlos para hallar la solución óptima del problema siguiente.
-   Se busca la mejor selección de monedas en una lista, con la restricción de que no se pueden seleccionar dos monedas adyacentes.
-   La recurrencia está dada por: `F[n] = max(F[n-1], F[n-2] + A[n])`, es decir, es el máximo entre agregar la moneda actual y tomar el caso óptimo para el caso que no considera a la moneda anterior aún, y el caso óptimo que sí la considera.

``` c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1000

int max(int a, int b) {
    return a < b ? b : a;
}

int main() {
    int coins[MAXN];
    int i = 0, tmp;
    while(scanf("%d", &tmp)) {
        if(tmp < 0) break;
        coins[i] = tmp;
        ++i;
    }
    int n = i;
    int sol[MAXN];
    memset(sol, 0, MAXN*sizeof(int));
    sol[0] = coins[0];
    sol[1] = max(coins[0], coins[1]);
    for(i = 2; i < n; ++i) {
        sol[i] = max(coins[i] + sol[i-2], sol[i-1]);
    }
    printf("%d\n", sol[n-1]);
    return 0;
}
```

### Longest Increasing Subsequence (LIS)

-   Dada una secuencia, hallar la longitud de la subsecuencia más grande de tal forma que todos los elementos estén ordenados en forma creciente.
-   La idea es ir guardando la longitud máxima posible que contiene al i-ésimo elemento como el último de la secuencia.
-   La complejidad es 𝒪(*n*<sup>2</sup>).

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
    memset(lis, 0, MAXN*sizeof(int));
    lis[0] = 1;
    for(i = 1; i < n; ++i) {
        for(j = 0; j < i; ++j) {
            if(seq[j] < seq[i] && lis[j]+1 > lis[i]) {
                lis[i] = lis[j]+1;
            }
        }
    }
    int max = 0;
    for(i = 0; i < n; ++i) {
        if(lis[i] > max) max = lis[i];
    }
    printf("Longest Increasing Subsequence: %d\n", max);
    return 0;
}
```

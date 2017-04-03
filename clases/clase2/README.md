Punteros
--------

En el siguiente código se tiene un ejemplo de manejo de punteros.

``` c
#include <stdio.h>
#include <stdlib.h>

void addAndSubstract(int a, int b, int* sum, int* diff);

int main(void){
    int a = 15;
    int b = 4;
    int *c = &a;

    int *sum = malloc(sizeof(int));
    int *diff = malloc(sizeof(int));

    // Devuelve el valor de a
    printf("a = %d\n", a);
    // Devuelve la dirección de a
    printf("&a = %d\n", &a);
    // Devuelve el valor de a
    printf("*c = %d\n", *c);
    // Devuelve la dirección de a
    printf("c = %d\n", c);

    addAndSubstract(a, b, sum, diff);
    printf("Suma: %d\n", *sum);
    printf("Resta: %d\n", *diff);

    return 0;
}

void addAndSubstract(int a, int b, int* sum, int* diff){
    *sum = a+b;
    *diff = a-b;
}
```

Los valores límite de los tipos de valor están en la librería `<limits.h>`. Se tienen valores como `INT_MAX` para el valor máximo del `int`.

Wedding
-------

El siguiente problema es sacado de [UVa 10662](https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1603).

``` c
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_COSAS 20

int main() {
    int T, R, H, i, j, k;
    while(scanf("%d %d %d", &T, &R, &H) == 3) {
        int agencias[T][R+1];
        int restaurantes[R][H+1];
        int hoteles[H][T+1];
        for(i = 0; i < T; i++){
            for(j = 0; j < R+1; j++){
                scanf("%d", &agencias[i][j]);
            }
        }
        for(i = 0; i < R; i++){
            for(j = 0; j < H+1; j++){
                scanf("%d", &restaurantes[i][j]);
            }
        }
        for(i = 0; i < H; i++){
            for(j = 0; j < T+1; j++){
                scanf("%d", &hoteles[i][j]);
            }
        }
        int minprecio = INT_MAX;
        int x, y, z;
        int puede = 0;
        /* Agencias */
        for(i = 0; i < T; i++){
            /* Restaurantes */
            for(j = 0; j < R; j++){
                /* Hoteles */
                for(k = 0; k < H; k++){
                    /* j=0 es el precio, por eso se aumenta 1 */
                    if(agencias[i][j+1] == 0 && restaurantes[j][k+1] == 0 && hoteles[k][i+1] == 0){
                        puede++;
                        if(minprecio > (agencias[i][0] + restaurantes[j][0] + hoteles[k][0])) {
                           minprecio = agencias[i][0] + restaurantes[j][0] + hoteles[k][0];
                           x = i;
                           y = j;
                           z = k;
                        }
                    }
                }
            }
        }
        if(puede==0){
            printf("Don't get married\n");
        } else {
            printf("%d %d %d: %d\n", x, y, z, minprecio);
        }
    }
    return 0;
}
```

Recursividad
============

-   El caso base es importante para evitar los bucles infinitos.

-   Recursión directa: Cuando la función se invoca a sí misma.
-   Recursión indirecta: Función que invoca a otra función que eventualmente resulta en invocar la primera función.

Número mayor
------------

``` c
#include <stdio.h>

#define MAX 10

int max(int a, int b);
int recursiveMax(int n, int a[n]);

int main(void) {
    int n, i, a[MAX], maximo;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    maximo = recursiveMax(n, a);
    printf("El maximo es: %d\n", &maximo);
    return 0;
}

int recursiveMax(int n, int a[n]) {
    if (n==1) return a[n-1];
    return max(a[n-1], recursiveMax(n-1, a));
}

int max(int a, int b){
    return a > b ? a : b;
}
```

Búsqueda secuencial
-------------------

``` c
#include <stdio.h>
#include <stdlib.h>

int busqueda(int n, int k, int* numeros);

int main() {
    int i, n, k;
    scanf("%d", &n);
    int* numeros = malloc(n*sizeof(int));
    for(i = 0; i < n; i++) {
        scanf("%d", &numeros[i]);
    }
    printf("Numero a buscar: ");
    scanf(" %d", &k);
    printf("%d", busqueda(n, k, numeros));
    return 0;
}

int busqueda(int n, int k, int* numeros) {
    if (numeros[n] == k) return n;
    else if (n == 0) return -1;
    else return busqueda(n-1, k, numeros);
}
```

Decimal a binario
-----------------

``` c
#include <stdio.h>

void d2b(int);

int main() {
    int n;
    scanf("%d", &n);
    d2b(n);
    printf("\n");
    return 1;
}

void d2b(int n) {
    if(n==0) return;
    d2b(n/2);
    printf("%d", n%2);
}
```

Palíndromos
-----------

``` c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

int esPalindromo(char cad[MAX], int i, int j);

int main() {
    char* cad = malloc(MAX*sizeof(char));
    fgets(cad, MAX, stdin);
    int palindromo = esPalindromo(cad, 0, strlen(cad));
    if(palindromo == 1)
        printf("Es palindromo\n");
    else
        printf("No es palindromo\n");
}

int esPalindromo(char cad[MAX], int i, int j){
    if(j <= i) return 1;
    if(cad[i] == cad[j]) {
        return esPalindromo(cad, i+1, j-1);
    }
    return 0;
}
```

-   En el caso de Fibonacci, no es recomendable usar recursividad pues se está llamando la misma función varias veces. Por ejemplo, para calcular f(4), se calcula f(2) y f(3). Para f(2), se tiene f(0) y f(1), y para f(3), se tiene f(2) y f(1). Pero a su vez, para calcular f(2) se debe obtener f(0) y f(1), siendo esto repetitivo.

Torres de Hanoi
---------------

``` c
#include <stdio.h>

void hanoi(int n, int source, int aux, int target);

int main() {
    int n;
    scanf("%d", &n);
    hanoi(n, 1, 2, 3);
    return 0;
}

void hanoi(int n, int source, int aux, int target) {
    if(n == 1) {
        printf("%d -> %d\n", source, target);
        return;
    }
    hanoi(n-1, source, target, aux);
    hanoi(1, source, aux, target);
    hanoi(n-1, aux, source, target);
    return;
}
```

Pregunta 1 del Lab 2015-2: Triángulo
------------------------------------

``` c
#include <stdio.h>
#include <stdlib.h>

void triangulo(int, int);

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    triangulo(a, b);
    return (EXIT_SUCCESS);
}

void triangulo(int a, int b) {
    int i;
    for(i = 0; i < a; i++) {
        printf("*");
    }
    printf("\n");
    if(a+1 <= b) triangulo(a+1, b);
    for(i = 0; i < a; i++) {
        printf("*");
    }
    printf("\n");
    return;
}
```

Transpuesta de la matriz
------------------------

Implementar una función recursiva que teniendo como únicos parámetros un arreglo bidimensional de enteros (el cual representa una matriz cuadrada de orden “N”) y el orden de la misma, permita obtener el mismo arreglo pero que contenga la transpuesta de dicha matriz. Nota: Se deberá trabajar únicamente con el arreglo bidimensional de enteros, sin utilizar ninguna estructura de datos adicional.

### Para el Laboratorio

-   Si se usa Netbeans: En la carpeta `/dist` está el ejecutable.
-   Si el ejecutable es `factorial`, se pone `factorial < test.in.txt` para leer un archivo. Para leer y escribir `factorial < test.in > out.txt`.
-   Para compilar: `gcc factorial.c -o factorial`.


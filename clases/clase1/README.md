Introducción del curso
======================

-   El profesor recomienda el IDE **Netbeans**.

-   El objetivo del curso es aprender a solucionar problemas a través de la definición de algoritmos.
-   En el mercado peruano generalmente no se usan métodos de programación complicados, pero sí en empresas grandes o que innovan.
-   Se busca ver estruturas de datos, punteros, árboles binarios de búsqueda, listas, un poco de grafos.
-   Se busca practicar de Online Judges como HackerRank, CodeForces.

-   La resolución de dudas es por previa coordinación por e-mail.

-   Los laboratorios son de 3 horas.
-   La media del curso suele ser ~10.

-   Parcial: Hasta ordenamiento.

-   Los exámenes son en computadora, con una parte teórica simple de ~2 preguntas, y parte práctica: Dos obligatorias y dos opcionales.
-   Las preguntas suelen sacar de los Online Judges.
-   Se recomienda traer laptop pues pueden haber trabajos en grupo.
-   Se recomienda usar Linux.

Fuerza bruta
============

-   Método directo para resolver un problema.
-   También conocido como **Búsqueda completa**.
-   Consiste en buscar en quizás todo el espacio de búsqueda.

Ordenación - Selección
----------------------

-   Encontrar el menor, ponerlo al comienzo. Luego buscar el menor en el resto de la lista, y colocarlo al segundo lugar. Así vamos haciendo que el espacio de búsqueda vaya siendo progresivamente más pequeño.

-   Precondición: Arreglo A\[0,...,n-1\] desordenado.
-   Postcondición: Arreglo A\[0,...,n-1\] ordenado.

1.  Ejemplo de ordenación por selección:
    -   6 5 8 2 1
    -   1| 5 8 2 6
    -   1 2 | 8 5 6
    -   1 2 5 | 8 6
    -   1 2 5 6 | 8

Ordenación - Burbuja
--------------------

-   Comparando adyacentes e ir cambiando el orden hasta encontrar la posición real del mayor (va subiendo hasta llegar al final).
-   Para trabajar con arreglos se empieza definiendo la longitud máxima del arreglo con define.

``` c
#include <stdio.h>

#define MAX 10

void bubblesort(int array[MAX], int n);
void print_array(int array[MAX], int n);

int main(void) {
    int n = 5;
    int array[MAX] = {6, 5, 8, 2, 1};
    bubblesort(array, n);
    print_array(array, n);
    return 0;
}

void bubblesort(int array[MAX], int n) {
    // n es el número de elementos real.
    for(int i=0; i<=n-2; i++) {
        print_array(array, n);
        for(int j=n-2-i; j>=0; j--) {
            if(array[j+1] > array[j]) {
                int tmp = array[j+1];
                array[j+1]= array[j];
                array[j] = tmp;
            }
        }
    }
}

void print_array(int array[MAX], int n) {
    for (int i=0; i<n; i++) {
        printf("%d\t", array[i]);
    }
    printf("\n");
}
```

Búsqueda - Secuencial
---------------------

-   Dado un conjunto de valores, encontrar un elemento dado.
-   Con el uso de estructuras de datos, podemos tener algoritmos rápidos para hacer búsquedas
-   Precondición: Arreglo A\[0,...,n-1\] y una llave de búsqueda K.
-   Postcondición: El índice del primer elemento.

``` c
#include <stdio.h>

#define MAX 20

int main() {
    int n = 9;
    int array[MAX] = {1, 1, 1, 5, 3, 1, 10, 3, 21};
    int K = 3;
    for (int i = 0; i <= n-1; i++) {
        if(array[i] == K) {
            printf("El índice donde está %d es: %d\n", K, i);
            return 0;
        }
    }
    printf("No se encontró el número %d\n", K);
    return 0;
}
```

Procesamiento de cadenas
------------------------

-   Algoritmo de [Levenshtein](https://en.wikipedia.org/wiki/Levenshtein_distance), distancia de edición. Usado para ver distancias entre palabras para sugerir palabras en corrección ortográfica.

String matching
---------------

-   Dada una cadena de tamaño n llamada *texto*, y una cadena de caracteres de tamaño m llamada *patrón* (m&lt;n), se busca una subcadena de caracteres dentro del texto que coincida con el patrón.
-   Se verifica caracter a caracter la ocurrencia del patrón en el texto. Si todos los caracteres no coinciden, se avanza el patrón un caracter a la derecha.

``` c
#include <stdio.h>

#define MAX 20

int main() {
    int n = 9;
    int array[MAX] = {1, 1, 1, 5, 3, 1, 10, 3, 21};
    int K = 3;
    for (int i = 0; i <= n-1; i++) {
        if(array[i] == K) {
            printf("El índice donde está %d es: %d\n", K, i);
            return 0;
        }
    }
    printf("No se encontró el número %d\n", K);
    return 0;
}
```

Closest pair
------------

-   Calcular distancia entre par de puntos e ir comparando dos a dos con un doble bucle.

Análisis de eficiencia
======================

-   Una solución es eficiente si logra resolver un problema dentro de limitaciones.
-   Una limitación puede ser el espacio, o el tiempo de ejecución.
-   Notación Big O.
-   𝒪(log *n*): Por ejemplo la búqueda binaria.
-   𝒪(*n*): Complejidad lineal, por ejemplo una búsqueda secuencial.
-   𝒪(*n*log *n*)
-   𝒪(2<sup>*n*</sup>): Exponencial.

1.  Ejemplo de análisis de eficiencia.

``` c
for(i=0; i<n; i++=) {
    a = a + 1;
}
```

Aquí, se tiene la fórmula:
$$
\\sum\_{i=0}^{n-1} 2 = 2n
$$
 Donde se usa 2 para denotar que hay dos unidades de tiempo cada vez. Esto es porque se están usandos dos operadores: + y =.

1.  La burbuja tiene complejidad 𝒪(*n*<sup>2</sup>).

2.  String matching tiene complejidad 𝒪(*n* × *m*), donde se consideran los tamaños del texto y el patrón.

3.  Closest pair: 𝒪(*n*<sup>2</sup>).

Tarea
=====

-   Codificar todos los ejercicios, y mandárselo al profesor.


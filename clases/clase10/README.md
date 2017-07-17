Algoritmia - Clase 10
=====================

Árboles
-------

-   Cada nodo tiene solamente un padre, con excepción de la raíz que no tiene padre alguno.
-   Para cada nodo, si consideramos todos sus descendientes se obtiene un subárbol.
-   *Nodos Hoja* (externos): No poseen descendientes.
-   *Nodos internos*: Poseen al menos un descendiente.
-   *Altura del árbol*: Longitud máxima desde un nodo para llegar a la raíz.

Árboles binarios
----------------

-   Cada nodo tiene a lo mucho dos hijos.
-   Hay tres formas de recorrer un árbol binario en función del orden en el que se visitan los nodos.

            3
        /       \

    4 5 / /
    2 8 9

-   *Preorden*: 3-4-2-5-8-9. Se visita primero la raíz y después los subárboles izquierdo en pre-orden y derecho en pre-orden.
-   *En orden*: 2-4-3-8-5-9. Se visita el subárbol izquierdo en orden, el nodo raíz y el subárbol derecho en orden.
-   *Postorden*: 2-4-8-9-5-3. Se visita el subárbol izquierdo en post-orden, el derecho en post-orden, y luego la raíz.
-   *En amplitud*: Por niveles. Para recorrerlo así, se usa una cola. Si el nodo raíz es diferente de NULL, entra en la cola. Mientras la cola no está vacía, se retira el primero de la cola. Si tiene hijos, ellos entran en la cola.
-   *En profundidad*: Es post-orden. Se puede implementar usando una pila.

Árbol binario de búsqueda (ABB)
-------------------------------

-   La llave de cada nodo del subárbol izquierdo de R es menor que la llave del nodo R.
-   La llave de cada nodo del subárbol derecho de R es mayor que la llave del nodo R.
-   Los árboles izquierdos y derechos son también ABBs.
-   Para hacer una búsqueda, se trabaja como en una búsqueda binaria.


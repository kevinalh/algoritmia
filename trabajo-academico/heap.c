#include <stdlib.h>
#include <float.h>

#include "graph.h"
#include "heap.h"

/**
* Inicializa el heap usando el tama�o dado para
* reservar el arreglo.
*/
void heapInitialize(THeap* h, int maxSize) {
	h->size = 0;
	h->array = malloc(maxSize*sizeof(THElement));
	h->table = malloc(maxSize * sizeof(int));
	if (h->array == NULL || h->table == NULL)
		reportError("Memory");
	return;
}

/**
* Devuelve �ndices de nodos relacionados en el heap.
*/
int heapParent(int index) {
	return (index - 1) / 2;
}

int heapLeftChild(int index) {
	return 2 * index + 1;
}

int heapRightChild(int index) {
	return 2 * index + 2;
}

/**
* Devuelve la ubicaci�n del v�rtice en el arreglo del
* binary heap.
*/
int heapIndexVertex(THeap* h, int vindex) {
	return h->table[vindex];
}

/**
* Inserta un �ndice de v�rtice al heap, de acuerdo al
* arreglo de distancias.
*/
void heapInsert(THeap* h, double* dist, THElement value) {
	int current, parent;
	current = h->size++;
	parent = current;
	while(current > 0) {
		current = parent;
		parent = heapParent(current);
		/* Si el padre  tiene una distancia menor, se cumple
		el heap condition */
		if (dist[h->array[parent]] <= dist[value]) break;
		/* Caso contrario, se tiene que intercambiar */
		h->array[current] = h->array[parent];
	}
	/* El nodo que nos quede al final almacenar� el valor */
	h->array[current] = value;
	h->table[value] = current;
	return;
}

/**
* Inserta un �ndice de v�rtice, sin hacer comparaciones.
* �til para la inicializaci�n del heap en Dijkstra, donde todos
* empiezan con distancia infinita (menos el primero).
*/
void heapInsertFast(THeap* h, THElement value) {
	int current = h->size++;
	h->array[current] = value;
	h->table[value] = current;
	return;
}

/**
* Funci�n que consigue restaurar el heap condition al eliminar la ra�z
* El par�metro value es el �ndice del heap array, no de la tabla de v�rtices
*/
void heapMinHeapify(THeap* h, double* dist, int value) {
	/* left, right son los hijos de value */
	int left = heapLeftChild(value);
	int right = left + 1;
	/* En smallest guardaremos el �ndice con menor distancia.
	A priori, este es el dado por value (la ra�z del sub�rbol) */
	int smallest = value;
	/* Revisamos que los hijos est�n en los l�mites del
	arreglo, y vemos si las distancias son efectivamente menores */
	if (left < h->size && dist[h->array[left]] < dist[h->array[smallest]]) {
		smallest = left;
	}
	if (right < h->size && dist[h->array[right]] < dist[h->array[smallest]]) {
		smallest = right;
	}
	/* Si la ra�z no es el m�s peque�o, tenemos que hacer un intercambio */
	if (smallest != value) {
		/* Hacemos un swap entre el padre y el menor hijo, de
		forma que se recupere el heap condition localmente */
		int tmp = h->array[value];
		h->array[value] = h->array[smallest];
		h->array[smallest] = tmp;
		tmp = h->table[h->array[value]];
		h->table[h->array[value]] = h->table[h->array[smallest]];
		h->table[h->array[smallest]] = tmp;
		/* Procedemos recursivamente */
		heapMinHeapify(h, dist, smallest);
	}
	return;
}

/**
* Elimina y devuelve el valor m�nimo en el heap, dado por la ra�z.
*/
THElement heapPopMinimum(THeap* h, double* dist) {
	if (heapIsEmpty(h)) reportError("Logic");
	/* last es el �ltimo elemento del �ltimo nivel del heap */
	THElement last = h->array[--h->size];
	THElement minimum = h->array[0];
	h->table[minimum] = -1;
	/* Lo mandamos a la ra�z */
	h->array[0] = last;
	h->table[last] = 0;
	/* Reordenamos el heap de manera que se siga cumpliendo su
	condici�n caracter�stica */
	heapMinHeapify(h, dist, 0);
	return minimum;
}

/**
* Disminuye el valor de un nodo en el heap.
*/
void heapDecreaseKey(THeap* h, double* dist, int vindex) {
	int x = heapIndexVertex(h, vindex);
	if (h->array[x] != vindex) reportError("Heap table");
	heapMinHeapify(h, dist, x);
	return;
}

/**
* Devuelve si el heap est� vac�o, fij�ndose s�lo en el tama�o.
*/
int heapIsEmpty(THeap* h) {
	return h->size == 0;
}

int heapFindMinimumLinear(TGraph* g, THeap* h, double* dist) {
	int i, k = -1;
	double curr, minimum = DBL_MAX;
	for (i = 0; i < g->size; ++i) {
		curr = dist[i];
		if (curr < minimum && heapIndexVertex(h, i) != -1) {
			minimum = curr;
			k = i;
		}
	}
	return k;
}

/**
* Libera la memoria del heap.
*/
void heapClean(THeap* h) {
	free(h->array);
	free(h->table);
	h->size = 0;
	return;
}
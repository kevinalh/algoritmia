#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main() {
    TPila p;
    pila_crear(&p);
    pila_apilar(&p, 4);
    pila_apilar(&p, 1);
    pila_apilar(&p, 8);
    printf("Desapilo 1: %d\n", pila_desapilar(&p));
    printf("Desapilo 2: %d\n", pila_desapilar(&p));
    return 0;
}

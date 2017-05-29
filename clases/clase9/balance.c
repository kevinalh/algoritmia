#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"

int parentesis() {
    TPila p;
    char exp[100];
    fgets(exp, 99, stdin);
    int len = strlen(exp);
    pila_crear(&p);
    if(exp[0] == ']' || exp[0] == ')') {
        return 0;
    }
    int i;
    TElement top;
    for(i = 0; i < len; ++i) {
        switch(exp[i]) {
            case ']':
                top = pila_tope(&p);
                if(top == '[')
                    pila_desapilar(&p);
                else
                    pila_apilar(&p, exp[i]);
                break;
            case ')':
                top = pila_tope(&p);
                if(top == '(')
                    pila_desapilar(&p);
                else
                    pila_apilar(&p, exp[i]);
                break;
            default:
                pila_apilar(&p, exp[i]);
                break;
        }
    }
    return pila_vacia(&p);
}

int main() {
    int a = parentesis();
    if(a == 1) {
        printf("Valido\n");
    } else {
        printf("Invalido\n");
    }
    return 0;
}

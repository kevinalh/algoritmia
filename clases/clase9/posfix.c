#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "pila.h"

int dos(TPila *p) {
    if(!pila_vacia(p)) {
        if(p->top->s != NULL) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char op[100];
    TPila p;
    pila_crear(&p);
    int i, len;
    int a, b, c;
    while(fgets(op, 99, stdin) && (len=strlen(op))>1) {
        if(isdigit(op[0])) {
            a = strtoll(op, NULL, 10);
            pila_apilar(&p, a);
        } 
        else {
            if(!dos(&p)) {
                printf("Insuficiente cantidad de operandos\n");
                continue;
            }
            b = pila_desapilar(&p);
            a = pila_desapilar(&p);
            switch(op[0]) {
                case '/':   
                    c = a/b;
                    break;
                case '*':
                    c = a*b;
                    break;
                case '+':
                    c = a+b;
                    break;
                case '-':
                    c = a-b;
                    break;
                default:
                    printf("No se reconoce lo ingresado\n");
            }
            pila_apilar(&p, c);
        }
    }
    printf("%d\n", pila_desapilar(&p));
    pila_finalizar(&p);
    return 0;
}

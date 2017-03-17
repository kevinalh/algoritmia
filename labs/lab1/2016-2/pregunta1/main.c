/* 
 * File:   main.c
 * Author: kevinalh
 *
 * Created on March 14, 2017, 10:05 PM
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_AMIGOS 5000
#define MAX_DIAS 366

int main() {
    // Cantidad de amigos
    int n;
    // Sexo de los amigos
    int s[MAX_AMIGOS];
    // Fechas iniciales en las que pueden asistir
    int a[MAX_AMIGOS];
    // Fechas finales en las que pueden asistir
    int b[MAX_AMIGOS];
    
    // Mejor caso encontrado hasta el momento
    int maximo = 0;
    int actual = 0;
    int gen = 0;
    
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d %d", &s[i], &a[i], &b[i]);
    }
    
    // Buscamos cuántos amigos entrarían cada día
    for(int dia = 1; dia < MAX_DIAS; dia++) {
        actual = 0;
        gen = 0;
        for(int amigo = 0; amigo < n; amigo++){
            if(a[amigo] <= dia && b[amigo] >= dia) {
                gen += s[amigo];
                actual++;
            }
        }
        if(gen % 3 != 0) actual--;
        if(maximo < actual) maximo = actual;
    }
    
    printf("El maximo es: %d \n", maximo);
    
    return(EXIT_SUCCESS);
}


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_PUNTOS 100

typedef struct punto{
    double x;
    double y;
    double z;
} punto;

double distancia(punto, punto);

int main() {
    int i = 0, j = 0, n = 0;
    scanf("%d", &n);
    if(n < 2){
        printf("Debe poner al menos dos puntos\n");
        return 1;
    }
    double x, y, z;
    punto puntos[n];
    for(i = 0; i < n; i++){
        scanf("%lf %lf %lf", &x, &y, &z);
        puntos[i].x = x;
        puntos[i].y = y;
        puntos[i].z = z;
    }
    double minimo = distancia(puntos[0], puntos[1]);
    int min1 = 0;
    int min2 = 1;
    double distactual = 0;
    // Buscamos el par de puntos más cercanos
    for(i = 0; i < n-1; i++){
        for(j = i+1; j < n; j++){
            distactual = distancia(puntos[i], puntos[j]);
            if(distactual < minimo) {
                minimo = distactual;
                min1 = i;
                min2 = j;
            }
        }
    }
    printf("El par de puntos más cercanos están en los índices %d y %d\n", min1, min2);
    printf("Su distancia es %lf", minimo);
    return 0;
}

double distancia(punto p1, punto p2){
    double dx = pow(p1.x - p2.x, 2);
    double dy = pow(p1.y - p2.y, 2);
    double dz = pow(p1.z - p2.z, 2);
    return sqrt(dx + dy + dz);
}

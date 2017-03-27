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

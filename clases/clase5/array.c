#include <stdio.h>
#include <math.h>

#define MAXN 100

int busqueda(int nums[MAXN], int t, int ini, int fin);

int main() {
    int nums[MAXN];
    int n = 0;
    int t = 0;
    scanf("%d", &t);
    while(scanf("%d", &nums[n]) == 1) {
        ++n;
    }
    int pos = busqueda(nums, t, 0, n);
    printf("Posicion: %d\n", pos);
    return 0;
}

int busqueda(int nums[MAXN], int t, int ini, int fin) {
    int pos = (ini + fin) / 2;
    if(nums[pos] == t) return pos;
    if(ini > fin) return -1;
    /* Verificamos que el primer segmento esta en orden */
    if(nums[ini] < nums[pos]) {
        if(t >= nums[ini] && t <= nums[pos]) {
            return busqueda(nums,  t, ini, pos-1);
        } else {
            return busqueda(nums, t, pos+1, fin);
        }
    } else {
        /* El otro esta ordenado */
        if(t >= nums[pos] && t <= nums[fin]) {
            return busqueda(nums,  t, pos+1, fin);
        } else {
            return busqueda(nums, t, ini, pos-1);
        }
    }
    return -1;
}

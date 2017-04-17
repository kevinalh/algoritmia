#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, k, r, precio;
    scanf("%d %d", &k, &r);
    for (i = 1; i < 10; i++) {
        precio = k*i;
        if(precio%10 == r || precio%10 == 0) {
            printf("%d", i);
            return 0;
        }
    }
    printf("10");
    return 0;
}

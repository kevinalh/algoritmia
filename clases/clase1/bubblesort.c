#include <stdio.h>

#define MAX 10

void bubblesort(int array[MAX], int n);
void print_array(int array[MAX], int n);

int main(void) {
    int n = 5;
    int array[MAX] = {6, 5, 8, 2, 1};
    bubblesort(array, n);
    print_array(array, n);
    return 0;
}

void bubblesort(int array[MAX], int n) {
    // n es el número de elementos real.
    for(int i=0; i<=n-2; i++) {
        print_array(array, n);
        for(int j=n-2-i; j>=0; j--) {
            if(array[j+1] > array[j]) {
                int tmp = array[j+1];
                array[j+1]= array[j];
                array[j] = tmp;
            }
        }
    }
}

void print_array(int array[MAX], int n) {
    for (int i=0; i<n; i++) {
        printf("%d\t", array[i]);
    }
    printf("\n");
}


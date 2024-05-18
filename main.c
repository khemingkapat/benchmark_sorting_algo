#include "stdio.h"
#include "stdlib.h"
#include <time.h>
#include "utils/readfile.h"
#include "utils/timereport.h"

void bubble_sort(int *arr, int n);

int main() {
    clock_t t;
    int f;
    int *arr = (int *)malloc(sizeof(int));
    int n = array_from_file(arr, "tests/normal1.txt");
    time_function(bubble_sort, arr,n);
    return 0;
}

void swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}


void bubble_sort(int *arr, int n) {
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j < i; j++) {
            /* printf("bubble at %d and %d\n",i,j); */
            if (arr[j - 1] > arr[j]) {
                swap(&arr[j-1],&arr[j]);
            }
        }
    }
}




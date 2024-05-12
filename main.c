#include "stdio.h"
#include "stdlib.h"
#include <time.h>
#include "utils/readfile.h"
#include "utils/timereport.h"

void bubble_sort(int *arr, int n);

int main() {
    clock_t start,end;
    double time;
    int *arr = (int *)malloc(sizeof(int));
    int n = array_from_file(arr, "tests/normal1.txt");
    time_function(bubble_sort,arr,n);
    return 0;
}

void swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}


void bubble_sort(int *arr, int n) {
    for (int i = n; i >= 1; i--) {
        /* printf("bubble at i = %d\n", i); */
        for (int j = 1; j < i; j++) {
            /* printf("\tbubble at j = %d\n", j); */
            if (arr[j - 1] > arr[j]) {
                swap(&arr[j-1],&arr[j]);
            }
        }
    }
}

#include "stdio.h"
#include "stdlib.h"
#include "utils/readfile.h"
#include "utils/timereport.h"
#include <time.h>

void bubble_sort(int *arr, int n);

int main() {
    clock_t t;
    int f;
    int *arr = (int *)malloc(sizeof(int));
    int n = array_from_file(arr, "tests/normal1.txt");
    double time_used = time_function(bubble_sort, arr, n);
    printf("time used = %lf ms\n",time_used*1000);

    return 0;
}

void bubble_sort(int *arr, int n) {
    int temp;
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j < i; j++) {
            if (arr[j - 1] > arr[j]) {
                temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

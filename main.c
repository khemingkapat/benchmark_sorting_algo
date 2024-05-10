#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "utils/readfile.h"
#include "utils/timereport.h"

void bubble_sort(int *arr, int n);

void fun() {
    printf("fun() starts \n");
    printf("Press enter to stop fun \n");
    while (1) {
        if (getchar())
            break;
    }
    printf("fun() ends \n");
}

int main() {
    int *arr = (int *)malloc(sizeof(int));

    int n = array_from_file(arr, "tests/normal1.txt");

    double time_used = time_function(bubble_sort,arr,n);
    printf("time used = %lf\n",time_used);
    

    return 0;
}

void bubble_sort(int *arr, int n) {
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j < i; j++) {
            if (arr[j - 1] > arr[j]) {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
}

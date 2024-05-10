#include "stdio.h"
#include "stdlib.h"
#include "utils/readfile.h"
#include "utils/timereport.h"

void bubble_sort(int *arr, int n);

int main() {
    int arr[] = {3, 1, 4, 2, 5};
    int n = 5;

    double time_used = time_function(bubble_sort, &arr, n);
    printf("%lf\n",time_used);

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

#include "stdio.h"
#include "stdlib.h"
#include "utils/readfile.h"

int main() {
    int *header = (int *)malloc(sizeof(int));
    int n = header_from_file(header, "test_file.txt");
    for (int i = 0; i < n; i++) {
        printf("%d ", header[i]);
    }
    puts("");

    int *arr = (int *)malloc(sizeof(int));
    n = array_from_file(arr, "test_file.txt");
    /* puts("got array"); */

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    puts("");

    return 0;
}

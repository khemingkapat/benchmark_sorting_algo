#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "utils/readfile.h"
#include "utils/sortalgos.h"

void write_report(char *sort_name, void (*sort)(int *, int), char *file_name) {

    int *arr = (int *)malloc(sizeof(int));

    int n = array_from_file(arr, file_name);

    /* double time_used = time_function(sort, arr, n) * 1000; */

    clock_t t;
    t = clock();
    printf("\r");
    sort(arr,n);
    /* printf("0\n"); */
    t = clock()-t;

    double time_used = (double)t * 1000 / CLOCKS_PER_SEC;

    printf("%s,%s,%lf\n", sort_name, file_name, time_used);

}
int main(int argc, char **argv){

    /* write_report("bubble", bubble_sort, argv[1]); */
    /* write_report("insertion", insertion_sort, argv[1]); */
    /* write_report("selection", selection_sort, argv[1]); */
    /* write_report("merge", merge_sort, argv[1]); */
    write_report("quick", quick_sort, argv[1]);


    return 0;
}

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "utils/readfile.h"
#include "utils/sortalgos.h"
#include "utils/timereport.h"



void write_report(char *sort_name, void (*sort)(int *, int), char *file_name) {

    FILE *fptr = fopen("result.csv", "w");

    for (int i = 1; i <= 100; i++) {

        int *arr = (int *)malloc(sizeof(int));
        char new_file_name[256];
        sprintf(new_file_name,"%s%d.txt",file_name,i);

        /* printf("filename = %s\n",new_file_name); */
        int n = array_from_file(arr, new_file_name);

        double time_used = time_function(sort, arr, n);

        /* fprintf(fptr, "hello,how,are you\n"); */
        fprintf(fptr, "%s,%s,%lf\n", sort_name, file_name, time_used);
        /* puts("done writing"); */
    }
    fclose(fptr);
}

int main() {
    write_report("bubble", bubble_sort, "tests/normal");

    return 0;
}

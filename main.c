#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main() {

    FILE *file = fopen("test_file.txt", "r");
    if (file == NULL) {
        puts("Error Opening File");
        return 0;
    }

    char buffer[10];

    do {
        fgets(buffer, 10, file);           // reading buffer
        buffer[strcspn(buffer, "\n")] = 0; // strip the eol
    } while (strcmp(buffer, "START"));

    int size = 0;
    int *arr = (int *)malloc(sizeof(int) * size);
    int idx = 0;

    /* while (!feof(file)) { */
    /*     size++; */
    /*     arr = (int *)realloc(arr, sizeof(int) * size); */
    /*     fgets(buffer, 10, file); */
    /*     buffer[strcspn(buffer, "\n")] = 0; // strip the eol */
    /*     printf("%d",atoi(buffer)); */
    /*     arr[idx] = atoi(buffer); */
    /*     idx++; */
    /*  */
    /*     fgets(buffer, 10, file); */
    /*     buffer[strcspn(buffer, "\n")] = 0; // strip the eol */
    /*     printf("%d",atoi(buffer)); */
    /*      */
    /* } */

    do {
        fgets(buffer, 10, file);
        buffer[strcspn(buffer, "\n")] = 0; // strip the eol
        printf("%d ",atoi(buffer));

    }while(!feof(file));
    fclose(file);

    /* for(int i = 0;i<size;i++){ */
    /*     printf("%d ",arr[i]); */
    /* } */
    puts("");
    return 0;
}

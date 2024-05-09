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

    while (fgets(buffer,10,file)!= NULL) {
        size++;
        arr = (int *)realloc(arr, sizeof(int) * size);
        buffer[strcspn(buffer, "\n")] = 0; // strip the eol
        arr[size-1] = atoi(buffer);
    
    }

    fclose(file);

    for(int i = 0;i<size;i++){
        printf("%d ",arr[i]);
    }
    puts("");
    return 0;
}

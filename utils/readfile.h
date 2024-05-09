#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#ifndef READFILE_H
#define READFILE_H

int header_from_file(int *ptr, char filename[]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        puts("Error Opening File.");
        return -1;
    }

    char line[10];


    int size = 0;
    
    while (strcmp(line, "START")){
        size++;
        fgets(line, 10, file);         // reading buffer
        ptr = (int *)realloc(ptr, sizeof(int) * size);
        line[strcspn(line, "\n")] = 0; // strip the eol
        ptr[size - 1] = atoi(line);
    }

    ptr = (int *)realloc(ptr,size--);

    return size;
}

int array_from_file(int *ptr, char filename[]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        puts("Error Opening File.");
        return -1;
    }

    char line[10];

    do {
        fgets(line, 10, file);         // reading buffer
        line[strcspn(line, "\n")] = 0; // strip the eol
    } while (strcmp(line, "START"));

    // now we at the starting point of array

    int size = 0;

    while (fgets(line, 10, file) != NULL) {
        size++;
        ptr = (int *)realloc(ptr, sizeof(int) * size);
        line[strcspn(line, "\n")] = 0; // strip the eol
        ptr[size - 1] = atoi(line);
    }

    fclose(file);

    return size;
}

#endif

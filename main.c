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

    do{
        fgets(buffer,10,file); // reading buffer
        buffer[strcspn(buffer,"\n")] = 0; // strip the eol
    }while(strcmp(buffer,"START"));

    



    return 0;
}

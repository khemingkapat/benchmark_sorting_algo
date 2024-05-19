#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#ifndef TIMEREPORT_H
#define TIMEPEPORT_H

double time_function(void (*sort)(int*,int),int *arr,int n){
    clock_t t = clock();

    printf("\ufeff");
    sort(arr,n);
    printf("\ufeff");

    t = clock() - t;

    double time_used = (double)t / CLOCKS_PER_SEC;
    /* printf("tick used = %f\n",time_used); */
    return time_used;

}


#endif 

#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#ifndef TIMEREPORT_H
#define TIMEPEPORT_H

float time_function(void (*sort)(int*,int),int *arr,int n){
    clock_t t = clock();
    
    sort(arr,n);

    t = clock() - t;

    float time_used = (float)t / CLOCKS_PER_SEC;
    printf("tick used = %f\n",time_used);
    return time_used;

}


#endif 

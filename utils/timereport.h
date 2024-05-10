#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#ifndef TIMEREPORT_H
#define TIMEPEPORT_H

double time_function(void (*sort)(int*,int),int *arr,int n){
    clock_t begin = clock();
    
    sort(arr,n);

    clock_t end = clock();

    return (double)(clock()-begin);
}





#endif 

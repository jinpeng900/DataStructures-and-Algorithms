#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int compare(const void *arg1 , const void *arg2)
{
    return (*(int*)arg1 - *(int*)arg2);
}

bool canMakeArithmeticProgression(int* arr, int arrSize) {
    qsort(arr , arrSize , sizeof(int) , compare);
    int n = arr[1] - arr[0];
    for(int i = 1 ; i < arrSize-1 ; i++)
    {
        if (arr[i+1] - arr[i] != n)
        {
            return false;
        }
    }
    return true;
}
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int findMinNumber(int * list , int len)
{
    int * arr;
    arr = (int *) malloc(sizeof(int) * (len + 2));
    memset(arr , 0 , len+2);
    arr[0] = 1;
    for (int i = 0 ; i < len ; i++)
    {
        if (list[i] > 0 && list[i] <= len)
        {
            arr[list[i]] = 1;
        }
    }
    for (int res = 0 ; res < len+2 ; res++)
    {
        if (arr[res] == 0)
        {
            return res;
        }
    }
}


int main()
{
    int nums[] = {1 , 2,3,4,5};
    int len = sizeof(nums) / sizeof(int);
    int num = findMinNumber(nums , len);
    printf("%d\n" , num);


    return 0;
}
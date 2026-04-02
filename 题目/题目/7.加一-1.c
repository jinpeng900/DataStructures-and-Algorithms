#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    for (int i = digitsSize-1 ; i >= 0 ; i--)
    {
        digits[i] = digits[i] + 1;
        if (digits[i] != 10)
        {
            *returnSize = digitsSize;
            return digits;
        }
        if (digits[i] == 10)
        {
            digits[i] = 0;
        }
    }
    int *ans = malloc(sizeof(int) * (digitsSize+1));
    memset(ans , 0 , sizeof(int) * (digitsSize + 1));
    ans[0] = 1;
    *returnSize = digitsSize + 1;
    return ans;
}

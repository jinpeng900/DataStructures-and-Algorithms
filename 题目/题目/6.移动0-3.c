#include<stdio.h>


void moveZeroes(int* nums , int numSize)
{
    int stack_size = 0;
    for (int i = 0 ; i < numSize ; i++)
    {
        if (nums[i] != 0)
        {
            nums[stack_size] = nums[i];
            stack_size++;
        }
    }
    for (int i = stack_size ; i < numSize ; i++)
    {
        nums[i] = 0;
    }
}

int main()
{
    int nums[] = {0 , 1 , 0 , 3 , 12};
    int len = sizeof(nums) / sizeof(int);
    moveZeroes(nums , len);
    for (int i = 0 ; i < len ; i++)
    {
        printf("%d\n" , nums[i]);
    }

    return 0;

}
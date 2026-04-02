#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


/*
如果数组是单调递增或单调递减的，那么它是单调的。
如果对于所有 i <= j，nums[i] <= nums[j]，那么数组 nums 是单调递增的。 如果对于所有 i <= j，nums[i] >= nums[j]，那么数组 nums 是单调递减的。
当给定的数组 nums 是单调数组时返回 true，否则返回 false。
*/


bool isMonotonic(int* nums, int numsSize)
{
    bool increase = true;
    bool decrease = true;
    for (int i = 1 ; i < numsSize ; i++)
    {
        if (nums[i-1] > nums[i])
        {
            increase = false;
        }
        else if(nums[i-1] < nums[i])
        {
            decrease = false;
        }
    }
    return increase || decrease;
}
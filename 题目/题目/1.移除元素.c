/*

给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素。元素的顺序可能发生改变。然后返回 nums 中与 val 不同的元素的数量。

*/
#include<stdio.h>


int removeElement(int* nums, int numsSize, int val)
{
    int Stack = 0;
    for (int i = 0 ; i < numsSize ; i++)
    {
        if (nums[i] != val)
        {
            nums[Stack++] = nums[i];
        }
    }
    return Stack;
}
// 解决最大子数组和问题。目标在于求解给定数组中找到一个连续的子数组，并求解其中最大的和

#include<stdio.h>

int Kadane(int * arr , int len)
{
    int Max_num = arr[0];
    int cur_num = arr[0];
    for (int i = 1 ; i < len ; i++)
    {
        cur_num = arr[i] + (cur_num > 0 ? cur_num : 0); 
        if (Max_num < cur_num)
        {
            Max_num = cur_num;
        }
    }
    return Max_num;
}


int main()
{
    int num[] = {-2 , 1 , -3 , 4 , -1 , 2 , 1 , -5 , 4};
    int len = sizeof(num) / sizeof(int);
    int max = Kadane(num , len);
    printf("%d\n" , max);


    return 0;
}

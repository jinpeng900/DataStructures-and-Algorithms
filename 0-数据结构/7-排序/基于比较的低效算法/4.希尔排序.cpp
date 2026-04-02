#include<iostream>

using namespace std;

void ShellSort(int arr[] , int n)
{
    int dk , i , j;
    for (dk = n / 2 ; dk >= 1 ; dk = dk / 2)
    {
        for (i = dk + 1 ; i <= n ; ++i)
        {
            if (arr[i] < arr[i-dk])
            {
                arr[0] = arr[i];
                for (j = i - dk ; j > 0 && arr[0] < arr[j] ; j-=dk)
                {
                    arr[j+dk] = arr[j];
                }
                arr[j + dk] = arr[0];
            }

        }
    }
}
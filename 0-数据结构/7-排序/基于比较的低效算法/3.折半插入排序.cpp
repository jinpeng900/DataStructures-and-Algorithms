#include<iostream>

using namespace std;

void InsertSort(int arr[] , int n)
{
    int i , j , low , high , mid;
    for (i = 2 ; i <= n ; i++)
    {
        arr[0] = arr[i];
        low = 1 , high = i - 1;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (arr[mid] > arr[0]) high = mid - 1;
            else low = mid + 1;
        }
        for (j = i - 1 ; j >= high + 1 ; j--)
        {
            arr[j+1] = arr[j];
        }
        arr[high + 1] = arr[0];
    }

}
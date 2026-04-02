#include<iostream>

using namespace std;

void InsertSort(int arr[] , int n)
{
    int i , j;
    for (i = 2 ; i <= n ; i++)
    {
        arr[0] = arr[i];
        for (j = i - 1 ; arr[j] > arr[0] ; j--)
        {
            arr[j+1] = arr[j];
        }
        arr[j+1] = arr[0];
    }
}




int main()
{
    int arr[9] = {0 , 49 , 38 , 65 , 97 , 76 , 13 , 27 , 49};
    int n = 8;
    InsertSort(arr , n);
    for (int i = 1 ; i <= 8 ; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;

}
#include<iostream>

using namespace std;

void swap(int &a , int &b)
{
    int t = a;
    a = b;
    b = t;
}


void BubbleSort(int arr[] , int n)
{
    for (int i = 0 ; i < n - 1 ; i++)
    {
        bool flag = false;
        for (int j = 2 ; j <= n - i ; j++)
        {
            if (arr[j - 1] > arr[j])
            {
                swap(arr[j-1] , arr[j]);
                flag = true;
            }
        }
        if (flag == false)
        {
            return;
        }
    }
}



int main()
{
    int n;
    cin >> n;
    int arr[n+1];
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> arr[i];
    }
    BubbleSort(arr , n);
    cout << " the result of sorting::" << endl;
    for (int i = 1 ; i <= n ; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}
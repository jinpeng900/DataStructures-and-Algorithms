#include<iostream>

using namespace std;

const int Num = 10000;
int arr[Num] = {0};

int main()
{
    int n;
    cout << "输入需要算的数的阶乘" << endl;
    cin >> n;
    arr[0] = 1;
    for (int i = 1 ; i <= n ; i++)
    {
        int carry = 0;
        for (int k = 0 ; k < Num ; k++)
        {
            arr[k] = arr[k] * i + carry;
            carry = arr[k] / 10;
            arr[k] = arr[k] % 10;
        }
    }
    int last;
    for (int i = Num-1 ; i >= 0 ; i--)
    {
        if (arr[i] != 0)
        {
            last = i;
            break;
        }
    }
    for (int i = last ; i >= 0 ; i--)
    {
        cout << arr[i];
    }
    return 0;

}
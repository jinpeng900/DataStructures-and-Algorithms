#include<iostream>
using namespace std;

int is_prime(int num)
{
    if (num == 1)
    {
        return 1;
    }
    for(int i = 2 ; i < num ; i++)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}


void Goldbach(int num)
{
    if (num % 2 != 0)
    {
        cout << "数据输入出错" << endl;
        return;
    }
    for (int i = 2 ; i < num ; i++)
    {
        if (is_prime(i)== 1 && is_prime(num-i) == 1)
        {
            cout << i << "+" << num-i << endl;
            return;
        }
    }
    cout << "验证错误" << endl;
    return;
}


int main()
{
    int num;
    cin >> num;
    Goldbach(num);
    system("pause");
    return 0;
}



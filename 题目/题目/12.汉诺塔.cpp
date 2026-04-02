#include<iostream>
#include<stdio.h>

using namespace std;

int count = 0;


int hanio(int n , char a , char b , char c)
{
    if (n == 1)
    {
        printf("%c -> %c\n" , a , c);
        count++;
    }
    else
    {
        hanio(n-1 , a , c , b);
        printf("%c -> %c\n" , a , c);
        hanio(n-1 , b , a , c);
        count++;
    }
    return count;
}

int main()
{
    int n;
    cin >> n;
    int num = hanio(n , 'a' , 'b' , 'c');
    printf("%d\n" , num);
    system("pause");
    return 0;
    
}
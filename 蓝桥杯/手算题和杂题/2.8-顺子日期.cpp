#include<iostream>

using namespace std;

int months[] = {0 , 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31};

bool check(string s)
{
    for (int i = 0 ; i+2 < s.size() ; i++)
    {
        if (s[i]+1 == s[i+1] && s[i]+2 == s[i+2])
        {
            return true;
        }
    }
    return false;
}


int main()
{
    int cnt = 0;
    int y = 2022;
    int m = 1;
    int d = 1;
    for (int i = 0 ; i < 365 ; i++)
    {
        char s[10];
        sprintf(s , "%04d%02d%02d" , y , m , d);
        if (check(s))
        {
            cnt++;
        }
        d++;
        if (d > months[m])
        {
            d = 1;
            m++;
        }
    }
    cout << cnt << endl;
    return 0;
    
}
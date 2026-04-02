#include<iostream>

using namespace std;

void Getnext(string str , int next[])
{
    int j , k;
    j = 0;
    k = -1;
    next[j] = k;
    while (j < str.size()-1)
    {
        if (k == -1 || str[k] == str[j])
        {
            k++;j++;
            next[j] = k;
        }
        else
        {
            k = next[k];
        }
    }
}


int Kmp(string &str , string &ex_str)
{
    int m = str.size();
    int n = ex_str.size();
    int next[ex_str.size()];
    Getnext(ex_str , next);
    int i = 0 ; int j = 0;
    while (i < m && j < n)
    {
        if (j == -1 || str[i] == ex_str[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }
    if (j >= n)
    {
        return (i - n);
    }
    else
    {
        return -1;
    }
}



int main()
{
    string str = "abcabeabcabcmn";
    string temp = "abcabcmn";
    int pos;
    pos = Kmp(str , temp);
    cout << pos << endl;
    return 0;
}
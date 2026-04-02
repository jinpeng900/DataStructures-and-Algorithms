#include<stdio.h>
#include<string.h>


int romanToInt(char * s)
{
    int symbol_num[26];
    symbol_num['I' - 'A'] = 1;
    symbol_num['V' - 'A'] = 5;
    symbol_num['X' - 'A'] = 10;
    symbol_num['L' - 'A'] = 50;
    symbol_num['C' - 'A'] = 100;
    symbol_num['D' - 'A'] = 500;
    symbol_num['M' - 'A'] = 1000;
    int len = strlen(s);
    int num = 0;
    for (int i = 0 ; i < len ; i++)
    {
        if (i < len - 1 && symbol_num[s[i] - 'A'] < symbol_num[s[i+1] - 'A'])
        {
            num -= symbol_num[s[i] - 'A'];
        }
        else
        {
            num += symbol_num[s[i] - 'A'];
        }
    }

    return num;
}

int main()
{
    char * s = "MDCLXVI";
    printf("%s\n", s);
    int num = romanToInt(s);
    printf("%d\n", num);
    return 0;
}
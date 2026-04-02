// 从 1 到 2022 的所有数字 ， 一共有多少个2
#include<stdio.h>

int main()
{
    int cnt = 0;
    for (int i = 1 ; i <= 2020 ; i++)
    {
        char buf[8] = "";
        sprintf(buf , "%d" , i);
        for (char*p=buf ; *p != '\0' ; p++)
        {
            if (*p == '2')
            {
                cnt++;
            }
        }
    }
    printf("%d\n" , cnt);
    return 0;
}
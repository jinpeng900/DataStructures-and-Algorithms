/*

给你两个字符串 haystack 和 needle ，
请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。
如果 needle 不是 haystack 的一部分，则返回  -1 。

*/
#include<stdio.h>
#include<string.h>

int strStr(char* haystack , char * needle)
{
    int haystackLen = strlen(haystack);
    int needleLen = strlen(needle);
    int i, j = 0;
    for (i = 0; i < haystackLen; i++)
    {
        if (haystack[i] == needle[j])
        {
            j++;
        }
        else
        {
            i = i - j;
            j = 0;
        }
        if (j == needleLen)
        {
            return i - j + 1;
        }
    }
    return -1;
}


char haystack[] = "sadbfsniadkanioaknsiujadnauiiaujdoadadbabiasaidbsdvjsasxaajsaddeffffesadefabcdefjnvdvofonqowfnnjs";
char needle[] = "abcd";
int main()
{
    int n = strStr(haystack , needle);
    printf("%d\n" , n);

    return 0;
}


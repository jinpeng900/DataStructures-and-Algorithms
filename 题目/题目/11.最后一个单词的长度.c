/*

给你一个字符串 s，由若干单词组成，单词前后用一些空格字符隔开。返回字符串中 最后一个 单词的长度。
单词 是指仅由字母组成、不包含任何空格字符的最大子字符串。

*/

#include<stdio.h>
#include<string.h>

int lenthOfLastword(char * s)
{
    int len = strlen(s);
    int num = 0;
    int last;
    for (int i = len - 1 ; i >= 0 ; i--)
    {
        if (s[i] != ' ')
        {
            last = i;
        }
    }
    for (int i = last ; i >= 0 ; i--)
    {
        if (s[i] == ' ')
        {
            break;
        }
        num++;
    }
    return num;
}
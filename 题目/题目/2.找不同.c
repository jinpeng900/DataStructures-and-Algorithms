/*

给定两个字符串 s 和 t ，它们只包含小写字母。

字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。

请找出在 t 中被添加的字母。

*/


// 异或运算补充

/*
异或运算，在计算机科学中，是一种重要的二进制运算。
它的特点是两个运算数的位中，相同则结果为0，不同则结果为1。在多种编程语言中，异或运算通常用符号“^”表示。
*/
#include<stdio.h>

char findTheDifference(char*s , char*t)
{
    int i = 0 , x = 0;
    while (s[i] != '\0')
    {
        x = x ^ s[i] ^ t[i];
        i++;
    }
    return x ^ t[i];
}

int main() {
    char *s = "abcd";
    char *t = "abcde";

    printf("%c\n" , findTheDifference(s , t));
    return 0;
}
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

bool isAnagram(char* s, char* t)
{
    int table[26] = {0};
    int s_len = strlen(s);
    int t_len = strlen(t);
    if (s_len != t_len)
    {
        return false;
    }
    for (int i = 0 ; i < s_len ; i++)
    {
        table[s[i] - 'a']++;
    }
    for (int i = 0 ; i < t_len ; i++)
    {
        table[t[i] - 'a']--;
    }
    for (int j = 0 ; j < 26 ; j++)
    {
        if (table[j] != 0)
        {
            return false;
        }
    }
    return true;
}


int main()
{
    char s[] = "abcde";
    char t[] = "ebcab";
    bool p = isAnagram(s , t);
    printf("%d\n" , p);




    return 0;
}

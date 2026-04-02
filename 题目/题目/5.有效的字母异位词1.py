# 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的 字母异位词。

def isAnagram(s:str , t:str) -> bool:
    d = {}
    if len(s) != len(t):
        return False
    for i in s:
        d[i] = d.get(i , 0) + 1
    for i in t:
        d[i] = d.get(i , 0) - 1
    for key in d:
        if d[key] != 0:
            return False
    return True


s = "abcdef"
t = "bcdtfa"

p = isAnagram(s , t)
print(p)
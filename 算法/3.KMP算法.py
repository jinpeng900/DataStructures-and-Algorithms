def GetNext(str):
    next = [0] * len(str)
    k = -1
    i = 0
    next[i] = k
    while i < len(str)-1:
        if k == -1 or str[k] == str[i]:
            k += 1
            i += 1
            next[i] = k
        else:
            k = next[k]
    return next

def KMP( father_str , son_str):
    i = 0
    j = 0
    next = GetNext(son_str)
    while i < len(father_str) and j < len(son_str):
        if j == -1 or father_str[i] == son_str[j]:
            i += 1
            j += 1
        else:
            j = next[j]
    if j >= len(son_str):
        return i - len(son_str)
    else:
        return -1
    

s1 = "abcabcdefmnabcdmn"
s2 = "abcdmn"
print(KMP(s1 , s2))
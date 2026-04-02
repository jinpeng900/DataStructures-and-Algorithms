def strStr(haystack:str , needle:str) -> int:
    if needle in haystack:
        return haystack.index(needle)
    else:
        return -1
haystack = "sadbfsniadkanioaknsiujadnauiiaujdoadadbabiasaidbsdvjsasxaajsaddeffffesadefabcdefjnvdvofonqowfnnjs"
needle = "abcd"
print(strStr(haystack , needle))
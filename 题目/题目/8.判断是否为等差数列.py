from typing import List


def canMakeArithmeticProgression(arr: List[int]) -> bool:
    arr = sorted(arr)
    t = arr[1] - arr[0]
    for i in range(1 , len(arr) - 1):
        if arr[i+1] - arr[i] != t:
            return False
    else:
        return True
        
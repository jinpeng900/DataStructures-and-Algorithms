"""
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

请注意 ，必须在不复制数组的情况下原地对数组进行操作。
"""


def moveZerroes(nums:list) -> list:
    for i in nums:
        if i == 0:
            nums.remove(0)
            nums.append(0)

    return nums

nums = [0 , 1 , 0 , 3 , 12]
lt = moveZerroes(nums)
print(lt)
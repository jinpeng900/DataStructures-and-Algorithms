def moveZeroes(nums:list) -> list:
    stack_size = 0
    for i in nums:
        if i != 0:
            nums[stack_size] = i
            stack_size += 1
    for i in range(stack_size , len(nums)):
        nums[i] = 0
    return nums


lt = moveZeroes([0 , 1 , 0 , 3 , 12])
print(lt)
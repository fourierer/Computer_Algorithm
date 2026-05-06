

# 对于遍历到的数x=nums[i]，如果x属于[1,n]，则交换nums[i]和nums[x-1]
# 如果交换后，nums[i]仍然属于[1,n]，则继续交换，直到nums[i]不属于[1,n]
# 同时防止死循环，应当保证交换的两个数不相等，即nums[x-1]!=nums[i]
# 如果都不符合上述条件，则跳出交换循环，遍历下一个数
# 以题目中的示例二 [3, 4, -1, 1] 为例，恢复后的数组应当为 [1, -1, 3, 4]，我们就可以知道缺失的数为 2


class Solution(object):
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        length = len(nums)
        for i in range(length):
            # x = nums[i];
            # 如果x在[1,n]中且nums[x-1]!=x，则将x换到x-1位置上
            while nums[i]>=1 and nums[i]<=length and nums[i]!=nums[nums[i]-1]:
                # self.swap1(nums[i], nums[nums[i]-1]) # 不会改变列表中两个位置的值
                self.swap2(nums, i)
                # print(nums)
                # nums[nums[i] - 1], nums[i] = nums[i], nums[nums[i] - 1]
        for j in range(length):
            if  nums[j] != j+1:
                return  j+1
        return length+1
        
    # def swap1(self, a, b):
    #     c = a
    #     a = b
    #     b = c
    def swap2(self, nums, i):
        index = nums[i]
        temp = nums[i]
        nums[i] = nums[nums[i] - 1]
        # 这里nums[i]的值已经被修改，所以需要用index
        nums[index - 1] = temp


if __name__=='__main__':
    s = Solution()
    nums = [3, 4, -1, 1]
    answer = s.firstMissingPositive(nums)
    print('final answer:', answer)

    # x = [1, 2, 3, 4]
    # def fun1(x):
    #     会直接改变列表x的值
    #     # x.append(5)
    #     temp = x[1]
    #     x[1] = x[2]
    #     x[2] = temp
    #     return x
    
    # def fun2(a, b):
    #     不会直接改变列表x的值
    #     temp = a
    #     a = b
    #     b = temp

    # def fun3(x, i):
    #     # 会直接改变列表x的值
    #     temp = x[i]
    #     x[i] = x[i+1]
    #     x[i+1] = temp

    
    # # # y = fun1(x)
    # # fun2(x[1], x[2])
    # fun3(x, 1)
    # # # print(y)
    # print(x)



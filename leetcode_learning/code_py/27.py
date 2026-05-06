
class Solution(object):
    # def removeElement(self, nums, val):
    #     """
    #     :type nums: List[int]
    #     :type val: int
    #     :rtype: int
    #     """
    #     # 这种方式是不对的，因为遍历nums的同时修改nums会改变当前遍历的位置
    #     for element in nums:
    #         print(nums)
    #         print(element)
    #         if element==val:
    #             nums.remove(val)
    #     return len(nums)
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        # 快慢双指针赋值
        length = len(nums)
        if length==0:
            return length
        i = 0
        for j in range(length):
            if nums[j]!=val:
                nums[i]=nums[j]
                i = i + 1
        return i

if __name__=='__main__':
    # x = [2,3,3,4,5,7,7]
    # x.remove(3) # 只删除一个
    # print(x)
    x = [3,3,1,3]
    s = Solution()
    print(s.removeElement(x, 3))
    print(x)





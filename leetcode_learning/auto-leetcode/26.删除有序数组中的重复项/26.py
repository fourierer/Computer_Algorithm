"""
26.删除有序数组中的重复项
难度：简单
链接：https://leetcode.cn/problems/remove-duplicates-from-sorted-array/
"""



class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:
        if not nums:
            return 0

        slow = 0  # 慢指针：指向当前不重复元素的末尾位置

        for fast in range(1, len(nums)):
            # 发现新元素（与慢指针指向的元素不同）
            if nums[fast] != nums[slow]:
                slow += 1  # 慢指针前进一步
                nums[slow] = nums[fast]  # 将新元素放到正确位置

        return slow + 1  # 不重复元素的个数





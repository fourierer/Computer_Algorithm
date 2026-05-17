"""
80.删除有序数组中的重复项II
难度：中等
链接：https://leetcode.cn/problems/remove-duplicates-from-sorted-array-ii/
"""


class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:
        # 本题 K=2，每个元素最多出现2次
        return self._remove_k_duplicates(nums, k=2)

    def _remove_k_duplicates(self, nums: list[int], k: int) -> int:
        # 通用解法：允许每个元素最多出现 K 次
        # 核心判断：nums[fast] != nums[slow - k + 1]
        # K=1 时退化为第26题，K=2 时即本题
        if len(nums) <= k:
            return len(nums)

        slow = k - 1  # 前K个元素直接保留，slow指向末尾
        for fast in range(k, len(nums)):
            # 与倒数第K个保留元素不同，说明当前元素出现不足K次
            if nums[fast] != nums[slow - k + 1]:
                slow += 1
                nums[slow] = nums[fast]
        return slow + 1
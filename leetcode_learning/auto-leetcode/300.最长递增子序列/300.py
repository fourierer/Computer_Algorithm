"""
300.最长递增子序列
难度：中等
链接：https://leetcode.cn/problems/longest-increasing-subsequence/
"""
from bisect import bisect_left
from typing import List


class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        # 动态规划 O(n²)
        # dp[i] 表示以 nums[i] 结尾的最长递增子序列长度
        # 对每个 i，检查前面所有比 nums[i] 小的 nums[j]，取最长的 dp[j] + 1
        dp = []
        for i in range(len(nums)):
            # 每个元素自身至少构成长度为 1 的递增子序列
            dp.append(1)
            for j in range(i):
                if nums[i] > nums[j]:
                    # nums[i] 可以接在 nums[j] 后面，长度为 dp[j] + 1
                    dp[i] = max(dp[i], dp[j] + 1)

        return max(dp)


class SolutionBinarySearch:
    def lengthOfLIS(self, nums: List[int]) -> int:
        # 贪心 + 二分查找 O(n log n)
        # tails[i] 表示长度为 i+1 的递增子序列的最小末尾元素
        # 维护更小的末尾，使后续元素更容易接上，从而可能形成更长的子序列
        tails = []
        for num in nums:
            # 在 tails 中找第一个 >= num 的位置
            pos = bisect_left(tails, num)
            if pos == len(tails):
                # num 比所有末尾都大，可以扩展子序列长度
                tails.append(num)
            else:
                # 替换为更小的末尾，让后续元素更容易接上
                tails[pos] = num

        return len(tails)
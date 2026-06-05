"""
198.打家劫舍
难度：中等
链接：https://leetcode.cn/problems/house-robber/
"""
from typing import List


class Solution:
    def rob(self, nums: List[int]) -> int:
        # 滚动变量：dp[i] 只依赖 dp[i-1] 和 dp[i-2]，用 first 和 second 代替整个数组
        # dp[i] = max(dp[i-1], dp[i-2] + nums[i])
        # - 偷第 i 家：不能偷第 i-1 家，金额 = dp[i-2] + nums[i]
        # - 不偷第 i 家：金额与到第 i-1 家时相同 = dp[i-1]
        n = len(nums)

        if n == 1:
            return nums[0]

        # first = dp[i-2]，second = dp[i-1]，初始为 dp[0] 和 dp[1]
        first, second = nums[0], max(nums[0], nums[1])

        for i in range(2, n):
            # 滚动更新：新的 second = max(不偷第i家, 偷第i家)
            # first 被更新为旧的 second，即 dp[i-2] → dp[i-1]
            first, second = second, max(second, first + nums[i])

        return second


class SolutionDP:
    def rob(self, nums: List[int]) -> int:
        # 一维 DP 数组：直观但空间为 O(n)
        n = len(nums)

        if n == 1:
            return nums[0]

        dp = [0] * n
        # 边界条件：只有一间房只能偷它，两间房偷金额更大的
        dp[0] = nums[0]
        dp[1] = max(nums[0], nums[1])

        for i in range(2, n):
            # 偷第 i 家 (dp[i-2]+nums[i]) vs 不偷第 i 家 (dp[i-1])
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i])

        return dp[n - 1]
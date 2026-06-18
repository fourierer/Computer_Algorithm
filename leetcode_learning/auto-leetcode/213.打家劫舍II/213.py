"""
213.打家劫舍II
难度：中等
链接：https://leetcode.cn/problems/house-robber-ii/
"""
from typing import List


class Solution:
    def rob(self, nums: List[int]) -> int:
        # 环形房屋：首尾相邻，不能同时偷第一家和最后一家
        # 拆成两个线性问题取较大值：
        #   情况 A：偷第一家 → 区间 nums[0..n-2]（不含最后一家）
        #   情况 B：不偷第一家 → 区间 nums[1..n-1]（不含第一家）
        n = len(nums)

        # 只有一间房时两个区间都会退化，单独处理
        if n == 1:
            return nums[0]

        def rob_range(l: int, r: int) -> int:
            # 在线性区间 nums[l..r] 上做 198 题的滚动 DP
            # dp[i] = max(dp[i-1], dp[i-2] + nums[i])
            if l == r:
                return nums[l]
            # first = dp[i-2]，second = dp[i-1]，初始为 dp[l] 和 dp[l+1]
            first, second = nums[l], max(nums[l], nums[l + 1])
            for i in range(l + 2, r + 1):
                # 偷第 i 家 = first + nums[i]（不能偷 i-1），不偷 = second
                first, second = second, max(second, first + nums[i])
            return second

        # 偷第一家（不含最后一家）vs 不偷第一家（不含第一家），取较大值
        return max(rob_range(0, n - 2), rob_range(1, n - 1))


class SolutionDP:
    def rob(self, nums: List[int]) -> int:
        # 一维 DP 数组版本：对两个子区间分别求解，取较大值
        n = len(nums)

        if n == 1:
            return nums[0]

        def rob_range(l: int, r: int) -> int:
            length = r - l + 1
            if length == 1:
                return nums[l]
            dp = [0] * length
            # 边界条件：区间内只有一间房偷它，两间房偷金额更大的
            dp[0] = nums[l]
            dp[1] = max(nums[l], nums[l + 1])
            for i in range(2, length):
                # 偷第 i 家 (dp[i-2]+nums[l+i]) vs 不偷第 i 家 (dp[i-1])
                dp[i] = max(dp[i - 1], dp[i - 2] + nums[l + i])
            return dp[length - 1]

        return max(rob_range(0, n - 2), rob_range(1, n - 1))

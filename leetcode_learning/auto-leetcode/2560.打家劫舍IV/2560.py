"""
2560.打家劫舍IV
难度：中等
链接：https://leetcode.cn/problems/house-robber-iv/
"""
from typing import List


class Solution:
    def minCapability(self, nums: List[int], k: int) -> int:
        # 二分能力值 x：check(x) 表示在 nums[i] <= x 的房屋中
        # 最多能偷多少间互不相邻的房屋；>= k 则 x 可行
        # 单调性：x 越大可偷数越多 → 二分最小可行 x

        def check(x: int) -> int:
            # 贪心：从左到右，遇到可偷的就偷并跳过相邻的下一间
            # 路径图最大独立集的贪心是最优的
            count = 0
            i = 0
            n = len(nums)
            while i < n:
                if nums[i] <= x:
                    count += 1
                    i += 2  # 偷了 i，相邻的 i+1 不能偷，直接跳过
                else:
                    i += 1
            return count

        # 搜索范围为值域 [min, max]
        lo, hi = min(nums), max(nums)
        while lo < hi:
            mid = (lo + hi) // 2
            if check(mid) >= k:
                hi = mid  # mid 可行，尝试更小的能力值
            else:
                lo = mid + 1  # mid 不可行，能力值必须更大
        return lo


class SolutionSorted:
    def minCapability(self, nums: List[int], k: int) -> int:
        # 在 nums 的去重排序值上二分，减少大值域下的二分轮次
        def check(x: int) -> int:
            count = 0
            i = 0
            n = len(nums)
            while i < n:
                if nums[i] <= x:
                    count += 1
                    i += 2
                else:
                    i += 1
            return count

        # 去重并排序得到候选能力值
        candidates = sorted(set(nums))
        lo, hi = 0, len(candidates) - 1
        while lo < hi:
            mid = (lo + hi) // 2
            if check(candidates[mid]) >= k:
                hi = mid
            else:
                lo = mid + 1
        return candidates[lo]

"""
209.长度最小的子数组
难度：中等
链接：https://leetcode.cn/problems/minimum-size-subarray-sum/
"""
from typing import List


class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        n = len(nums)
        ans = n + 1  # 初始设为不可能的大值
        left = 0
        total = 0

        for right in range(n):
            total += nums[right]
            # 当窗口和 >= target 时，尝试收缩左端点
            while total >= target:
                ans = min(ans, right - left + 1)
                total -= nums[left]
                left += 1

        return 0 if ans == n + 1 else ans
"""
11.盛最多水的容器
难度：中等
链接：https://leetcode.cn/problems/container-with-most-water/
"""
from typing import List


class Solution:
    def maxArea(self, height: List[int]) -> int:
        # 双指针从两端向中间收缩
        left, right = 0, len(height) - 1
        max_area = 0

        while left < right:
            # 面积 = 较短边的高度 × 宽度
            max_area = max(max_area, (right - left) * min(height[left], height[right]))

            # 移动较短边：只有移动较短边才可能遇到更高的线，从而增大面积
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1

        return max_area

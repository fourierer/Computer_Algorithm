"""
55.跳跃游戏
难度：中等
链接：https://leetcode.cn/problems/jump-game/
"""
from typing import List


class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n = len(nums)
        rightmost = 0  # 当前能到达的最远位置

        for i in range(n):
            # 只有当前位置可达时，才更新最远位置
            if i <= rightmost:
                rightmost = max(rightmost, i + nums[i])
            # 最远位置已覆盖终点，可以到达
            if rightmost >= n - 1:
                return True

        # 遍历结束仍未到达终点
        return False
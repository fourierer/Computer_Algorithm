"""
45.跳跃游戏II
难度：中等
链接：https://leetcode.cn/problems/jump-game-ii/
"""
from typing import List


class Solution:
    def jump(self, nums: List[int]) -> int:
        n = len(nums)
        rightmost = 0  # 当前能到达的最远位置
        step = 0       # 跳跃次数
        end = 0        # 当前这一步的边界

        for i in range(n - 1):
            # 只有当前位置可达时，才更新最远位置
            if i <= rightmost:
                rightmost = max(rightmost, i + nums[i])
            # 遍历到边界，必须再跳一步进入下一层
            if i == end:
                end = rightmost
                step += 1

        return step
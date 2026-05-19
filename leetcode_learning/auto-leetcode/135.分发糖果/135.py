"""
135.分发糖果
难度：困难
链接：https://leetcode.cn/problems/candy/
"""
from typing import List


class Solution:
    def candy(self, ratings: List[int]) -> int:
        n = len(ratings)
        # 从左到右：满足左规则（比左边评分高则糖果比左边多）
        left = [0] * n
        for i in range(n):
            if i > 0 and ratings[i] > ratings[i - 1]:
                left[i] = left[i - 1] + 1
            else:
                left[i] = 1

        # 从右到左：满足右规则，用变量滚动计算，省去 right 数组
        right = ret = 0
        for i in range(n - 1, -1, -1):
            if i < n - 1 and ratings[i] > ratings[i + 1]:
                right += 1
            else:
                right = 1
            # 取两个方向的较大值，同时满足左右规则
            ret += max(left[i], right)

        return ret
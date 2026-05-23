"""
57.插入区间
难度：中等
链接：https://leetcode.cn/problems/insert-interval/
"""

from typing import List


class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        result = []
        i = 0
        n = len(intervals)

        # 阶段1：将完全在新区间左侧的区间直接加入结果
        while i < n and intervals[i][1] < newInterval[0]:
            result.append(intervals[i])
            i += 1

        # 阶段2：合并所有与新区间重叠的区间
        while i < n and intervals[i][0] <= newInterval[1]:
            newInterval[0] = min(newInterval[0], intervals[i][0])
            newInterval[1] = max(newInterval[1], intervals[i][1])
            i += 1

        result.append(newInterval)

        # 阶段3：将剩余的区间加入结果
        while i < n:
            result.append(intervals[i])
            i += 1

        return result


if __name__ == "__main__":
    sol = Solution()
    assert sol.insert([[1, 3], [6, 9]], [2, 5]) == [[1, 5], [6, 9]]
    assert sol.insert([[1, 2], [3, 5], [6, 7], [8, 10], [12, 16]], [4, 8]) == [[1, 2], [3, 10], [12, 16]]
    assert sol.insert([], [5, 7]) == [[5, 7]]
    assert sol.insert([[1, 5]], [2, 3]) == [[1, 5]]
    assert sol.insert([[1, 5]], [6, 8]) == [[1, 5], [6, 8]]
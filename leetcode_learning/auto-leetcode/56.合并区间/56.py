"""
56.合并区间
难度：中等
链接：https://leetcode.cn/problems/merge-intervals/
"""

from typing import List


class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        # 按左端点排序，使得重叠区间一定相邻
        intervals.sort(key=lambda x: x[0])
        merged = []

        for interval in intervals:
            # 若结果为空或当前区间与最后一个区间不重叠，直接加入
            if not merged or interval[0] > merged[-1][1]:
                merged.append(interval)
            else:
                # 重叠时合并，右端点取较大值
                merged[-1][1] = max(merged[-1][1], interval[1])

        return merged


if __name__ == "__main__":
    sol = Solution()
    assert sol.merge([[1, 3], [2, 6], [8, 10], [15, 18]]) == [[1, 6], [8, 10], [15, 18]]
    assert sol.merge([[1, 4], [4, 5]]) == [[1, 5]]
    assert sol.merge([[1, 4], [0, 4]]) == [[0, 4]]
    assert sol.merge([[1, 4], [2, 3]]) == [[1, 4]]
    assert sol.merge([[1, 4]]) == [[1, 4]]
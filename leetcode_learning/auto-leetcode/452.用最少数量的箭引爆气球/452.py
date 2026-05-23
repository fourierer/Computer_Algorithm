"""
452.用最少数量的箭引爆气球
难度：中等
链接：https://leetcode.cn/problems/minimum-number-of-arrows-to-burst-balloons/
"""

from typing import List


class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        if not points:
            return 0

        # 按右端点排序，贪心地让每支箭尽可能向右延伸
        points.sort(key=lambda x: x[1])

        arrows = 1
        pos = points[0][1]  # 第一支箭的位置

        for start, end in points[1:]: # for (i, j) in xxx 或者 for [i, j] in xxx均可
            # 当前气球的左端点大于箭的位置，说明不重叠，需要新箭
            if start > pos:
                arrows += 1
                pos = end

        return arrows


if __name__ == "__main__":
    sol = Solution()
    assert sol.findMinArrowShots([[10, 16], [2, 8], [1, 6], [7, 12]]) == 2
    assert sol.findMinArrowShots([[1, 2], [3, 4], [5, 6], [7, 8]]) == 4
    assert sol.findMinArrowShots([[1, 2], [2, 3], [3, 4], [4, 5]]) == 2
    assert sol.findMinArrowShots([]) == 0
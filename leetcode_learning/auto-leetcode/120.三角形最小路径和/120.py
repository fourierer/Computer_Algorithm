"""
120.三角形最小路径和
难度：中等
链接：https://leetcode.cn/problems/triangle/
"""
from typing import List


class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        # 二维 DP：f[i][j] 表示从顶点到第 i 行第 j 列的最小路径和
        # 状态转移：f[i][j] = min(f[i-1][j-1], f[i-1][j]) + triangle[i][j]
        # 每个位置只能从上一行相邻的两个位置到达（下标相同或下标减一）
        n = len(triangle)
        f = [[0] * n for _ in range(n)]
        f[0][0] = triangle[0][0]

        for i in range(1, n):
            # 左边界：只能从上一行最左端到达
            f[i][0] = f[i - 1][0] + triangle[i][0]
            # 中间位置：从上一行相邻两个位置中选较小的
            for j in range(1, i):
                f[i][j] = min(f[i - 1][j - 1], f[i - 1][j]) + triangle[i][j]
            # 右边界：只能从上一行最右端到达
            f[i][i] = f[i - 1][i - 1] + triangle[i][i]

        # 最小路径和是最后一行中的最小值
        return min(f[n - 1])


class SolutionOptimized:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        # 空间优化：f[i][j] 只依赖 f[i-1][j-1] 和 f[i-1][j]
        # 用一维数组从右往左更新，避免覆盖还未使用的值
        n = len(triangle)
        f = [0] * n
        f[0] = triangle[0][0]

        for i in range(1, n):
            # 右边界：必须先更新，因为只依赖 f[i-1]
            f[i] = f[i - 1] + triangle[i][i]
            # 中间位置：从右往左更新，保证 f[j] 和 f[j-1] 都是上一行的值
            for j in range(i - 1, 0, -1):
                f[j] = min(f[j - 1], f[j]) + triangle[i][j]
            # 左边界：只依赖 f[0]
            f[0] = f[0] + triangle[i][0]

        return min(f)
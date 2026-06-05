"""
64.最小路径和
难度：中等
链接：https://leetcode.cn/problems/minimum-path-sum/
"""
from typing import List


class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        # dp[i][j] 表示从左上角到 (i,j) 的最小路径和
        # 只能向下或向右移动，因此 (i,j) 只能从 (i-1,j) 或 (i,j-1) 到达
        rows, columns = len(grid), len(grid[0])
        dp = [[0] * columns for _ in range(rows)]
        dp[0][0] = grid[0][0]

        # 第一列：只能从上方到达
        for i in range(1, rows):
            dp[i][0] = dp[i - 1][0] + grid[i][0]
        # 第一行：只能从左边到达
        for j in range(1, columns):
            dp[0][j] = dp[0][j - 1] + grid[0][j]

        # 中间位置：从上方和左方中选较小的路径
        for i in range(1, rows):
            for j in range(1, columns):
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j]

        return dp[rows - 1][columns - 1]


class SolutionInPlace:
    def minPathSum(self, grid: List[List[int]]) -> int:
        # 原地修改：直接在 grid 上计算，无需额外 DP 数组
        rows, columns = len(grid), len(grid[0])

        for i in range(rows):
            for j in range(columns):
                if i == 0 and j == 0:
                    continue
                elif i == 0:
                    # 第一行：只能从左边到达
                    grid[i][j] += grid[i][j - 1]
                elif j == 0:
                    # 第一列：只能从上方到达
                    grid[i][j] += grid[i - 1][j]
                else:
                    # 从上方和左方中选较小的路径
                    grid[i][j] += min(grid[i - 1][j], grid[i][j - 1])

        return grid[rows - 1][columns - 1]
"""
63.不同路径II
难度：中等
链接：https://leetcode.cn/problems/unique-paths-ii/
"""
from typing import List


class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        # dp[i][j] 表示从左上角到 (i,j) 的不同路径数
        # 障碍物处路径数为 0，非障碍物处 dp[i][j] = dp[i-1][j] + dp[i][j-1]
        n, m = len(obstacleGrid), len(obstacleGrid[0])
        dp = [[0] * m for _ in range(n)]

        # 起点：非障碍物则路径数为 1，障碍物则路径数为 0（整个网格无解）
        dp[0][0] = 1 if obstacleGrid[0][0] == 0 else 0

        # 第一列：只能从上方到达，遇到障碍物则该位置及下方都为 0
        for i in range(1, n):
            dp[i][0] = dp[i - 1][0] if obstacleGrid[i][0] == 0 else 0

        # 第一行：只能从左边到达，遇到障碍物则该位置及右方都为 0
        for j in range(1, m):
            dp[0][j] = dp[0][j - 1] if obstacleGrid[0][j] == 0 else 0

        # 其余位置：非障碍物处从上方和左方路径数相加
        for i in range(1, n):
            for j in range(1, m):
                if obstacleGrid[i][j] == 0:
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
                # 障碍物处 dp[i][j] 保持初始值 0，无法通过

        return dp[n - 1][m - 1]
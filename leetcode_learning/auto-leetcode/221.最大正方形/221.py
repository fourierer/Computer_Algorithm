"""
221.最大正方形
难度：中等
链接：https://leetcode.cn/problems/maximal-square/
"""
from typing import List


class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        # dp[i][j] 表示以 (i,j) 为右下角的最大正方形边长
        # 若 matrix[i][j] == '1'：
        #   dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
        # 若 matrix[i][j] == '0'：
        #   dp[i][j] = 0
        # 取 min 的原因：正方形要求四边完整，三个方向中最短的决定了能扩展的边长
        m, n = len(matrix), len(matrix[0])
        dp = [[0] * n for _ in range(m)]
        max_side = 0

        for i in range(m):
            for j in range(n):
                if matrix[i][j] == '1':
                    if i == 0 or j == 0:
                        # 第一行或第一列：单独一个格子构成边长为 1 的正方形
                        dp[i][j] = 1
                    else:
                        # 取三个方向的最小值 +1，保证正方形四边完整
                        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1
                    max_side = max(max_side, dp[i][j])
                # matrix[i][j] == '0' 时 dp[i][j] 保持初始值 0

        return max_side * max_side
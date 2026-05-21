"""
48.旋转图像
难度：中等
链接：https://leetcode.cn/problems/rotate-image/
"""
from typing import List


class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        n = len(matrix)
        # 顺时针旋转90° = 水平翻转 + 对角线翻转：先水平(i,j)→(n-1-i,j)，再对角线→(j,n-1-i)
        # 注意：对角线翻转 + 水平翻转 = 逆时针90°：先对角线(i,j)→(j,i)，再水平→(n-1-j,i)
        # 第一步：沿水平中线上下翻转
        # (i, j) → (n-1-i, j)
        for i in range(n // 2):
            for j in range(n):
                matrix[i][j], matrix[n - 1 - i][j] = matrix[n - 1 - i][j], matrix[i][j]

        # 第二步：沿主对角线翻转
        # (i, j) → (j, i)
        for i in range(n):
            for j in range(i):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]




"""
73.矩阵置零
难度：中等
链接：https://leetcode.cn/problems/set-matrix-zeroes/
"""
from typing import List


class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        m, n = len(matrix), len(matrix[0])
        # 必须在标记之前记录，否则标记会污染第一行/列的原始信息
        first_row_zero = any(matrix[0][j] == 0 for j in range(n))
        first_col_zero = any(matrix[i][0] == 0 for i in range(m))

        # 用第一行和第一列作为标记位，记录哪些行和列需要置零
        for i in range(1, m):
            for j in range(1, n):
                if matrix[i][j] == 0:
                    matrix[i][0] = 0
                    matrix[0][j] = 0

        # 根据标记位置零（先处理内部，避免覆盖标记）
        for i in range(1, m):
            if matrix[i][0] == 0:
                for j in range(1, n):
                    matrix[i][j] = 0
        for j in range(1, n):
            if matrix[0][j] == 0:
                for i in range(1, m):
                    matrix[i][j] = 0

        # 处理第一行和第一列（必须放最后，否则会破坏标记位）
        # 此时用的 first_row_zero / first_col_zero 是标记之前记录的原始值
        if first_row_zero:
            for j in range(n):
                matrix[0][j] = 0
        if first_col_zero:
            for i in range(m):
                matrix[i][0] = 0
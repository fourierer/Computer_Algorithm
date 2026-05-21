"""
54.螺旋矩阵
难度：中等
链接：https://leetcode.cn/problems/spiral-matrix/
"""
from typing import List


class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix or not matrix[0]:
            return []

        top, bottom = 0, len(matrix) - 1
        left, right = 0, len(matrix[0]) - 1
        result = []

        while top <= bottom and left <= right:
            # 从左到右遍历上边界
            for j in range(left, right + 1):
                result.append(matrix[top][j])
            top += 1

            # 从上到下遍历右边界
            for i in range(top, bottom + 1):
                result.append(matrix[i][right])
            right -= 1

            # 从右到左遍历下边界，防止单行时重复遍历
            # 例如 [[1,2,3,4]]：上边界已遍历 1,2,3,4，top 变为 1 > bottom(0)
            # 此时下边界若不加检查会反向再走一遍 4,3,2,1
            if top <= bottom:
                for j in range(right, left - 1, -1):
                    result.append(matrix[bottom][j])
                bottom -= 1

            # 从下到上遍历左边界，防止单列时重复遍历
            # 例如 [[1],[2],[3]]：右边界已遍历 2,3，right 变为 -1 < left(0)
            # 此时左边界若不加检查会反向再走一遍 3,2
            if left <= right:
                for i in range(bottom, top - 1, -1):
                    result.append(matrix[i][left])
                left += 1

        return result
"""
6.Z字形变换
难度：中等
链接：https://leetcode.cn/problems/zigzag-conversion/
"""


class Solution:
    def convert(self, s: str, numRows: int) -> str:
        n, r = len(s), numRows
        # 特判：单行或行数足够时直接返回
        if r == 1 or r >= n:
            return s
        # 周期长度：竖直 r 个 + 斜线 r-2 个
        t = r * 2 - 2
        # 计算矩阵列数
        c = (n + t - 1) // t * (r - 1)
        mat = [[''] * c for _ in range(r)]
        x, y = 0, 0
        for i, ch in enumerate(s):
            mat[x][y] = ch
            if i % t < r - 1:
                x += 1  # 向下移动
            else:
                x -= 1
                y += 1  # 向右上移动
        return ''.join(ch for row in mat for ch in row if ch)
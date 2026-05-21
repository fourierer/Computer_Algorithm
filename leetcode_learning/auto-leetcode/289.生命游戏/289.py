"""
289.生命游戏
难度：中等
链接：https://leetcode.cn/problems/game-of-life/
"""
from typing import List


class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        m, n = len(board), len(board[0])
        # 八个方向
        directions = [(-1, -1), (-1, 0), (-1, 1),
                       (0, -1),          (0, 1),
                       (1, -1),  (1, 0), (1, 1)]

        # 用二进制位编码：低位(bit0)存当前状态，高位(bit1)存下一状态
        # 0(00): 死→死, 1(01): 活→死, 2(10): 死→活, 3(11): 活→活
        for i in range(m):
            for j in range(n):
                # 统计活邻居数量（用 bit0 判断当前状态）
                live_neighbors = 0
                for di, dj in directions:
                    ni, nj = i + di, j + dj
                    if 0 <= ni < m and 0 <= nj < n and board[ni][nj] & 1:
                        live_neighbors += 1

                # 规则2：活细胞有2或3个活邻居，下一状态存活
                # 规则4：死细胞恰好有3个活邻居，下一状态存活
                # 两种情况下将 bit1 置1，表示下一状态为活
                if (board[i][j] & 1 and live_neighbors in (2, 3)) or \
                   (not (board[i][j] & 1) and live_neighbors == 3):
                    board[i][j] |= 2

        # 右移1位：bit1变为bit0，得到最终状态
        for i in range(m):
            for j in range(n):
                board[i][j] >>= 1
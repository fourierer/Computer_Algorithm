"""
130.被围绕的区域
难度：中等
链接：https://leetcode.cn/problems/surrounded-regions/
"""
from collections import deque
from typing import List


class Solution:
    def solve(self, board: List[List[str]]) -> None:
        # 核心思路：与边界相连的 'O' 不会被围绕，从边界出发标记所有不被围绕的 'O'
        # 步骤：1.边界 'O' 标记为 'A'  2.BFS 扩展标记  3.还原 'A'→'O'，翻转 'O'→'X'
        if not board or not board[0]:
            return

        m, n = len(board), len(board[0])
        que = deque()

        # 第一步：将四条边界上的 'O' 入队并标记为 'A'（表示不被围绕）
        # 左右边界
        for i in range(m):
            if board[i][0] == "O":
                que.append((i, 0))
                board[i][0] = "A"
            if board[i][n - 1] == "O":
                que.append((i, n - 1))
                board[i][n - 1] = "A"
        # 上下边界（跳过四个角，避免重复）
        for i in range(1, n - 1):
            if board[0][i] == "O":
                que.append((0, i))
                board[0][i] = "A"
            if board[m - 1][i] == "O":
                que.append((m - 1, i))
                board[m - 1][i] = "A"

        # 第二步：BFS 扩展，将从边界可达的所有 'O' 标记为 'A'
        while que:
            x, y = que.popleft()
            for mx, my in [(x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)]:
                if 0 <= mx < m and 0 <= my < n and board[mx][my] == "O":
                    # 入队时立即标记，防止重复入队
                    que.append((mx, my))
                    board[mx][my] = "A"

        # 第三步：遍历矩阵，'A' 还原为 'O'，剩余的 'O' 被围绕则翻转为 'X'
        for i in range(m):
            for j in range(n):
                if board[i][j] == "A":
                    board[i][j] = "O"
                elif board[i][j] == "O":
                    board[i][j] = "X"


class SolutionDFS:
    def solve(self, board: List[List[str]]) -> None:
        # DFS：从边界出发，递归标记所有与边界相连的 'O'
        if not board or not board[0]:
            return

        m, n = len(board), len(board[0])

        def dfs(x: int, y: int) -> None:
            # 越界或不是 'O'，直接返回
            if not (0 <= x < m and 0 <= y < n) or board[x][y] != "O":
                return
            # 标记为 'A'，表示与边界相连，不会被翻转
            board[x][y] = "A"
            dfs(x - 1, y)
            dfs(x + 1, y)
            dfs(x, y - 1)
            dfs(x, y + 1)

        # 从四条边界出发 DFS
        for i in range(m):
            dfs(i, 0)
            dfs(i, n - 1)
        for i in range(1, n - 1):
            dfs(0, i)
            dfs(m - 1, i)

        # 还原 'A'→'O'，翻转 'O'→'X'
        for i in range(m):
            for j in range(n):
                if board[i][j] == "A":
                    board[i][j] = "O"
                elif board[i][j] == "O":
                    board[i][j] = "X"
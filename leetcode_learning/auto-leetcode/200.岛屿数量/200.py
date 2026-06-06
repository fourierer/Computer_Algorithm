"""
200.岛屿数量
难度：中等
链接：https://leetcode.cn/problems/number-of-islands/
"""
from collections import deque
from typing import List


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        # BFS：遇到 '1' 就是一道新岛屿，BFS 将整个连通块标记为 '0'
        nr = len(grid)
        nc = len(grid[0])

        num_islands = 0
        for r in range(nr):
            for c in range(nc):
                if grid[r][c] == "1":
                    num_islands += 1
                    # 入队时立即标记为 '0'，防止同一节点被重复入队
                    grid[r][c] = "0"
                    neighbors = deque([(r, c)])

                    while neighbors:
                        row, col = neighbors.popleft()
                        # 上下左右四个方向
                        for x, y in [(row - 1, col), (row + 1, col), (row, col - 1), (row, col + 1)]:
                            if 0 <= x < nr and 0 <= y < nc and grid[x][y] == "1":
                                # 入队时立即标记，而非出队时才标记
                                # 否则同一节点可能被多个邻居重复入队
                                grid[x][y] = "0"
                                neighbors.append((x, y))

        return num_islands


class SolutionDFS:
    def numIslands(self, grid: List[List[str]]) -> int:
        # DFS：遇到 '1' 就递归标记整个连通块
        nr = len(grid)
        nc = len(grid[0])

        num_islands = 0
        for r in range(nr):
            for c in range(nc):
                if grid[r][c] == "1":
                    num_islands += 1
                    self._dfs(grid, r, c)

        return num_islands

    def _dfs(self, grid: List[List[str]], r: int, c: int) -> None:
        # 先标记当前节点为已访问
        grid[r][c] = "0"
        nr, nc = len(grid), len(grid[0])
        # 递归访问四个方向的邻居
        for x, y in [(r - 1, c), (r + 1, c), (r, c - 1), (r, c + 1)]:
            if 0 <= x < nr and 0 <= y < nc and grid[x][y] == "1":
                self._dfs(grid, x, y)
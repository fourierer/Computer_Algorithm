"""
36.有效的数独
难度：中等
链接：https://leetcode.cn/problems/valid-sudoku/
"""
from typing import List


class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        # 一次遍历，用三个哈希表同时检查行、列、宫
        rows = [{} for _ in range(9)]
        cols = [{} for _ in range(9)]
        boxes = [{} for _ in range(9)]

        for i in range(9):
            for j in range(9):
                val = board[i][j]
                if val == '.':
                    continue
                # 宫编号：行号//3 * 3 + 列号//3
                b = (i // 3) * 3 + (j // 3)
                if val in rows[i] or val in cols[j] or val in boxes[b]:
                    return False
                rows[i][val] = True
                cols[j][val] = True
                boxes[b][val] = True

        return True

    def isValidSudoku_set(self, board: List[List[str]]) -> bool:
        # 集合解法：分别遍历行、列、宫
        for i in range(9):
            seen = set()
            for j in range(9):
                if board[i][j] != '.' and board[i][j] in seen:
                    return False
                seen.add(board[i][j])

        for j in range(9):
            seen = set()
            for i in range(9):
                if board[i][j] != '.' and board[i][j] in seen:
                    return False
                seen.add(board[i][j])

        for start_i in range(0, 9, 3):
            for start_j in range(0, 9, 3):
                seen = set()
                for i in range(start_i, start_i + 3):
                    for j in range(start_j, start_j + 3):
                        if board[i][j] != '.' and board[i][j] in seen:
                            return False
                        seen.add(board[i][j])

        return True
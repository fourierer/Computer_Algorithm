"""
72.编辑距离
难度：中等
链接：https://leetcode.cn/problems/edit-distance/
"""
from typing import List


class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        m, n = len(word1), len(word2)
        # dp[i][j] 表示 word1[:i] 转换成 word2[:j] 的最少操作数
        # 尺寸 (m+1)×(n+1)：i 取 0..m，j 取 0..n
        # i=0 对应空串，j=0 也对应空串；+1 是为了容纳空串边界，否则递推缺少初始值
        dp = [[0 for _ in range(n + 1)] for _ in range(m + 1)]

        # 边界条件：word1[:i] 变成空串需要删除 i 次
        for i in range(m + 1):
            dp[i][0] = i
        # 边界条件：空串变成 word2[:j] 需要插入 j 次
        for j in range(n + 1):
            dp[0][j] = j

        # 状态转移
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if word1[i - 1] == word2[j - 1]:
                    # 末尾字符相同，无需额外操作，直接继承左上角
                    dp[i][j] = dp[i - 1][j - 1]
                else:
                    # 末尾字符不同，取三种操作的最小值
                    dp[i][j] = min(
                        dp[i - 1][j - 1] + 1,  # 替换：把 word1[i-1] 换成 word2[j-1]
                        dp[i][j - 1] + 1,        # 插入：在 word1 末尾插入 word2[j-1]
                        dp[i - 1][j] + 1,        # 删除：删除 word1[i-1]
                    )

        return dp[m][n]
"""
1143.最长公共子序列
难度：中等
链接：https://leetcode.cn/problems/longest-common-subsequence/
"""
from typing import List


class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        m, n = len(text1), len(text2)
        # dp[i][j] 表示 text1[:i] 和 text2[:j] 的最长公共子序列长度
        # 尺寸 (m+1)×(n+1)：i 取 0..m，j 取 0..n
        # i=0 和 j=0 对应空串边界，+1 是为了容纳空串初始值，否则递推缺少初始值
        dp = [[0] * (n + 1) for _ in range(m + 1)]

        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if text1[i - 1] == text2[j - 1]:
                    # 末尾字符相同，可以加入公共子序列，长度 +1
                    dp[i][j] = dp[i - 1][j - 1] + 1
                else:
                    # 末尾字符不同，两者不可能同时出现在公共子序列中，至少要舍弃一个
                    # dp[i-1][j]：舍弃 text1[i-1]，用 text1[:i-1] 匹配 text2[:j]
                    # dp[i][j-1]：舍弃 text2[j-1]，用 text1[:i] 匹配 text2[:j-1]
                    # 取较大值即保留更长的子序列；dp[i-1][j-1] 不需单独考虑，已包含在两者中
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

        return dp[m][n]
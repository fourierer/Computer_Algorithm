"""
139.单词拆分
难度：中等
链接：https://leetcode.cn/problems/word-break/
"""
from typing import List


class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        word_set = set(wordDict)
        # 优化：只遍历最大单词长度范围内的 j，避免全扫描
        max_len = max(len(w) for w in wordDict) if wordDict else 0
        n = len(s)

        # dp[i] = s[0..i-1] 能否被字典拆分
        dp = [False] * (n + 1)
        dp[0] = True  # 空串可拆分

        for i in range(1, n + 1):
            # 优化：j 只在 [i - max_len, i) 范围内尝试
            # 原因：s[j:i] 要能在字典中找到，其长度 i-j 不可能超过字典最长单词 max_len
            # 若 i-j > max_len，s[j:i] 比字典任何单词都长，s[j:i] in word_set 必为 False
            # 跳过这些 j 避免无意义查找，复杂度从 O(n^2) 降到 O(n * max_len)
            for j in range(max(0, i - max_len), i):
                if dp[j] and s[j:i] in word_set:
                    dp[i] = True
                    break  # 找到一个合法切分即可

        return dp[n]

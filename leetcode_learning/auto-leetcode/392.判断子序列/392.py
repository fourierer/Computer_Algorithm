"""
392.判断子序列
难度：简单
链接：https://leetcode.cn/problems/is-subsequence/
"""


class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        n, m = len(s), len(t)
        i = j = 0

        while i < n and j < m:
            if s[i] == t[j]:
                i += 1
            j += 1

        # 一定是n，如果是n-1说明s最后一个字符不匹配
        return i == n
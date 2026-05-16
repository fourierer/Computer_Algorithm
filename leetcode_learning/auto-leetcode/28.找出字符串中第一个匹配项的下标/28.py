"""
28.找出字符串中第一个匹配项的下标
难度：简单
链接：https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/
"""
from typing import List


class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        # 暴力匹配：逐个起始位置尝试
        n, m = len(haystack), len(needle)
        for i in range(n - m + 1):
            if haystack[i:i + m] == needle:
                return i
        return -1


class SolutionKMP:
    def strStr(self, haystack: str, needle: str) -> int:
        if not needle:
            return 0

        # 构建 next 数组（最长相等前后缀长度）
        next_arr = self._build_next(needle)

        j = 0  # needle 中当前匹配位置
        for i in range(len(haystack)):
            # 失配时根据 next 数组回退 j
            while j > 0 and haystack[i] != needle[j]:
                j = next_arr[j - 1]
            # 当前字符匹配，j 前进
            if haystack[i] == needle[j]:
                j += 1
            # 完全匹配，返回起始下标
            if j == len(needle):
                return i - j + 1

        return -1

    def _build_next(self, needle: str) -> List[int]:
        next_arr = [0] * len(needle)
        j = 0  # 当前最长相等前后缀长度
        for i in range(1, len(needle)):
            # 失配时回退 j
            while j > 0 and needle[i] != needle[j]:
                j = next_arr[j - 1]
            # 前后缀字符匹配，长度加1
            if needle[i] == needle[j]:
                j += 1
            next_arr[i] = j
        return next_arr
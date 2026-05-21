"""
76.最小覆盖子串
难度：困难
链接：https://leetcode.cn/problems/minimum-window-substring/
"""
from collections import defaultdict


class Solution:
    def minWindow(self, s: str, t: str) -> str:
        need = defaultdict(int)
        for ch in t:
            need[ch] += 1
        need_count = len(need)

        window = defaultdict(int)
        formed = 0

        left = 0
        start, min_len = 0, len(s) + 1

        for right, ch in enumerate(s):
            if ch in need:
                window[ch] += 1
                # 该字符数量刚好满足需求
                if window[ch] == need[ch]:
                    formed += 1

            # 窗口满足所有字符需求时，尝试收缩左端点
            while formed == need_count:
                # 更新最短子串
                if right - left + 1 < min_len:
                    start = left
                    min_len = right - left + 1

                # 收缩左端点
                left_ch = s[left]
                if left_ch in need:
                    if window[left_ch] == need[left_ch]:
                        formed -= 1
                    window[left_ch] -= 1
                left += 1

        return "" if min_len == len(s) + 1 else s[start:start + min_len]
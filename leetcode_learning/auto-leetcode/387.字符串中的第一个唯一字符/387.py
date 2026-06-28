"""
387.字符串中的第一个唯一字符
难度：简单
链接：https://leetcode.cn/problems/first-unique-character-in-a-string/
"""


class Solution:
    def firstUniqChar(self, s: str) -> int:
        # 第一趟：循环统计每个字符出现次数（不借用 Counter）
        # 用字典累加，遍历到字符就给它的计数 +1
        count = {}
        for c in s:
            count[c] = count.get(c, 0) + 1
        # 第二趟：找第一个频次为 1 的字符索引
        for i, c in enumerate(s):
            if count[c] == 1:
                return i
        return -1

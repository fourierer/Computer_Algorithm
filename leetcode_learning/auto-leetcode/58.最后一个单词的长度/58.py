"""
58.最后一个单词的长度
难度：简单
链接：https://leetcode.cn/problems/length-of-last-word/
"""


class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        n = len(s)
        index = n - 1
        # 跳过尾部空格
        while s[index] == ' ':
            index -= 1
        result = 0
        # 从最后一个单词的末尾向前计数
        for i in range(index, -1, -1):
            if s[i] != ' ':
                result += 1
            else:
                break
        return result
"""
151.反转字符串中的单词
难度：中等
链接：https://leetcode.cn/problems/reverse-words-in-a-string/
"""


class Solution:
    def reverseWords(self, s: str) -> str:
        return ' '.join(reversed(s.split()))

    def reverseWords_two_pointer(self, s: str) -> str:
        # 从末尾开始，双指针定位每个单词
        result = []
        i = len(s) - 1
        while i >= 0:
            # 跳过空格
            while i >= 0 and s[i] == ' ':
                i -= 1
            if i < 0:
                break
            # 右指针标记单词末尾
            j = i
            # 左指针向左找到单词起始
            while i >= 0 and s[i] != ' ':
                i -= 1
            # 提取单词加入结果
            result.append(s[i + 1:j + 1])
        return ' '.join(result)
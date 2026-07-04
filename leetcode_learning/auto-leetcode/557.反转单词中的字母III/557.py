"""
557.反转单词中的字母III
难度：简单
链接：https://leetcode.cn/problems/reverse-words-in-a-string-iii/
"""


class Solution:
    def reverseWords(self, s: str) -> str:
        # 按空格切分，每个单词反转后拼接
        word_list = s.split(' ')
        result = []
        for word in word_list:
            result.append(word[::-1])
        return ' '.join(result)


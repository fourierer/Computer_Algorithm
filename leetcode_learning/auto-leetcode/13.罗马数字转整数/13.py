"""
13.罗马数字转整数
难度：简单
链接：https://leetcode.cn/problems/roman-to-integer/
"""


class Solution:
    def romanToInt(self, s: str) -> int:
        mapping = {'I': 1, 'V': 5, 'X': 10, 'L': 50,
                    'C': 100, 'D': 500, 'M': 1000}

        result = 0
        for i in range(len(s) - 1):
            # 当前值小于右边值，说明是减法组合（如 IV、IX）
            if mapping[s[i]] < mapping[s[i + 1]]:
                result -= mapping[s[i]]
            else:
                result += mapping[s[i]]
        # 最后一位总是加上
        result += mapping[s[-1]]

        return result
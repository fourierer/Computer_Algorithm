"""
12.整数转罗马数字
难度：中等
链接：https://leetcode.cn/problems/integer-to-roman/
"""


class Solution:
    def intToRoman(self, num: int) -> str:
        # 值-符号对，从大到小排列，包含所有特殊减法组合
        pairs = [
            (1000, 'M'), (900, 'CM'), (500, 'D'), (400, 'CD'),
            (100, 'C'), (90, 'XC'), (50, 'L'), (40, 'XL'),
            (10, 'X'), (9, 'IX'), (5, 'V'), (4, 'IV'), (1, 'I')
        ]

        result = []
        for value, symbol in pairs:
            # 贪心：尽可能多用当前最大面值
            count, num = divmod(num, value)
            result.append(symbol * count)
            if num == 0:
                break

        return ''.join(result)
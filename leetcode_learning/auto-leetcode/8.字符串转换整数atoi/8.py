"""
8.字符串转换整数(atoi)
难度：中等
链接：https://leetcode.cn/problems/string-to-integer-atoi/
"""


class Solution:
    def myAtoi(self, s: str) -> int:
        INT_MAX = 2 ** 31 - 1
        INT_MIN = -2 ** 31

        i, n = 0, len(s)
        # 1. 跳过前导空格
        while i < n and s[i] == ' ':
            i += 1
        if i == n:
            return 0

        # 2. 读取符号
        sign = 1
        if s[i] == '+' or s[i] == '-':
            sign = -1 if s[i] == '-' else 1
            i += 1

        # 3. 逐位读数字，提前判断溢出
        res = 0
        while i < n and s[i].isdigit():
            d = ord(s[i]) - ord('0')
            # 提前判断溢出（避免用 long）：
            # 正数上界 INT_MAX = 2147483647，INT_MAX // 10 = 214748364
            # 若 res 已超 INT_MAX//10，或等于且当前位 > 7，则溢出截断
            if res > INT_MAX // 10 or (res == INT_MAX // 10 and d > 7):
                return INT_MAX if sign == 1 else INT_MIN
            res = res * 10 + d
            i += 1

        return sign * res

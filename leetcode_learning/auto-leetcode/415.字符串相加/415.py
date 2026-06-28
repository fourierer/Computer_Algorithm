"""
415.字符串相加
难度：简单
链接：https://leetcode.cn/problems/add-strings/
"""


class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        # 模拟手工加法：从末尾逐位相加，维护进位 carry
        i, j = len(num1) - 1, len(num2) - 1
        carry = 0
        res = []

        while i >= 0 or j >= 0 or carry:
            # 取当前位数字，越界则按 0 处理
            d1 = ord(num1[i]) - ord('0') if i >= 0 else 0
            d2 = ord(num2[j]) - ord('0') if j >= 0 else 0
            total = d1 + d2 + carry
            carry = total // 10
            res.append(str(total % 10))
            i -= 1
            j -= 1

        # res 是逆序的（低位在前），翻转后拼接
        return ''.join(reversed(res))

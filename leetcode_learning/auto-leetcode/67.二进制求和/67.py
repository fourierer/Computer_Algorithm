"""
67.二进制求和
难度：简单
链接：https://leetcode.cn/problems/add-binary/
"""


class Solution:
    def addBinary(self, a: str, b: str) -> str:
        # 与字符串相加同构，进制改为 2
        i, j = len(a) - 1, len(b) - 1
        carry = 0
        res = []

        while i >= 0 or j >= 0 or carry:
            d1 = ord(a[i]) - ord('0') if i >= 0 else 0
            d2 = ord(b[j]) - ord('0') if j >= 0 else 0
            total = d1 + d2 + carry
            carry = total // 2
            res.append(str(total % 2))
            i -= 1
            j -= 1

        return ''.join(reversed(res))

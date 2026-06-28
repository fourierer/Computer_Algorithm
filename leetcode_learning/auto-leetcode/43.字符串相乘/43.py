"""
43.字符串相乘
难度：中等
链接：https://leetcode.cn/problems/multiply-strings/
"""


class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        # 特判：任一为 0 则乘积为 0
        if num1 == "0" or num2 == "0":
            return "0"

        m, n = len(num1), len(num2)
        # 乘积最多 m + n 位
        res = [0] * (m + n)

        # 核心 trick：num1[i] * num2[j] 的乘积落在 res[i+j] 和 res[i+j+1]
        # 先逐位相乘并累加（不立即进位）
        for i in range(m - 1, -1, -1):
            d1 = ord(num1[i]) - ord('0')
            for j in range(n - 1, -1, -1):
                d2 = ord(num2[j]) - ord('0')
                res[i + j + 1] += d1 * d2

        # 从右向左统一处理进位
        for k in range(m + n - 1, 0, -1):
            res[k - 1] += res[k] // 10
            res[k] %= 10

        # 跳过前导零，转为字符串
        start = 0
        while start < len(res) and res[start] == 0:
            start += 1
        return ''.join(str(d) for d in res[start:])

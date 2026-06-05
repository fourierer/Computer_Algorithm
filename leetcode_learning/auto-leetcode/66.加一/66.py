"""
66.加一
难度：简单
链接：https://leetcode.cn/problems/plus-one/
"""
from typing import List


class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        n = len(digits)
        # 从末尾开始往前找，模拟加法进位
        for i in range(n - 1, -1, -1):
            if digits[i] != 9:
                # 当前位不是 9，加 1 后不会进位
                digits[i] += 1
                # 当前位之后的所有位都是 9，需要置 0
                for j in range(i + 1, n):
                    digits[j] = 0
                return digits
        # 所有位都是 9（如 [9,9,9]），加一后变为 [1,0,0,0]
        return [1] + [0] * n
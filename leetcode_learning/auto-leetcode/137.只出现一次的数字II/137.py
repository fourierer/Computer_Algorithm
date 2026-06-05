"""
137.只出现一次的数字II
难度：中等
链接：https://leetcode.cn/problems/single-number-ii/
"""
from typing import List


class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        # 逐位统计：每个比特位上 1 出现的总次数对 3 取余，
        # 余数就是只出现一次的数在该位的值
        # 原理：出现三次的数在每个比特位上贡献的 1 的个数是 3 的倍数，取余为 0
        ans = 0
        for i in range(32):
            total = sum((num >> i) & 1 for num in nums)
            if total % 3:
                if i == 31:
                    # Python 特殊处理：整数是任意精度的，没有固定 32 位
                    # 第 31 位是符号位，若为 1 说明结果是负数
                    # 1 << 31 在 Python 中是正数 2147483648，不会自动变成负数
                    # 用 ans -= (1 << 31) 将其转为负数，等同于 32 位有符号整数的负数表示
                    ans -= (1 << i)
                else:
                    # 第 i 位为 1，用或运算置位
                    ans |= (1 << i)
        return ans
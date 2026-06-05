"""
191.位1的个数
难度：简单
链接：https://leetcode.cn/problems/number-of-1-bits/
"""


class Solution:
    def hammingWeight(self, n: int) -> int:
        # n & (n - 1)：每次消除 n 最低位的 1
        # 例如 n = 10110, n-1 = 10101, n & (n-1) = 10100（最低位的 1 被去掉）
        # 循环次数 = 1 的个数，比逐位检查更高效
        ret = 0
        while n:
            n &= n - 1
            ret += 1
        return ret


class SolutionBitCheck:
    def hammingWeight(self, n: int) -> int:
        # 逐位检查：与 1 << i 做与运算，判断第 i 位是否为 1
        ret = sum(1 for i in range(32) if n & (1 << i))
        return ret
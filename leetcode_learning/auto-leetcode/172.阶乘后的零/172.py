"""
172.阶乘后的零
难度：中等
链接：https://leetcode.cn/problems/factorial-trailing-zeroes/
"""


class Solution:
    def trailingZeroes(self, n: int) -> int:
        # 尾随零的数量 = n! 中因子 10 的个数 = min(因子2的个数, 因子5的个数)
        # 因子 2 远多于因子 5，所以只需统计因子 5 的个数
        #
        # n! 中因子 5 的个数 = n//5 + n//25 + n//125 + ...
        # 即：5的倍数贡献1个5，25的倍数额外贡献1个5，125的倍数再额外贡献1个5...
        # 等价于反复将 n 除以 5 并累加商
        ans = 0
        while n:
            n //= 5
            ans += n
        return ans
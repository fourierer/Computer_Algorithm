"""
50.Pow(x, n)
难度：中等
链接：https://leetcode.cn/problems/powx-n/
"""


class Solution:
    def myPow(self, x: float, n: int) -> float:
        # 递归快速幂：利用 x^n = (x^(n/2))² 将问题规模减半
        def quickMul(N: int) -> float:
            # 递归终止：任何数的 0 次幂为 1
            if N == 0:
                return 1.0
            # 递归计算 x^(N//2)
            y = quickMul(N // 2)
            # 若 N 为偶数：x^N = (x^(N//2))²
            # 若 N 为奇数：x^N = (x^(N//2))² × x，多乘一个 x 补上
            return y * y if N % 2 == 0 else y * y * x

        # n 可能为负数，x^(-n) = 1 / x^n
        return quickMul(n) if n >= 0 else 1.0 / quickMul(-n)


class SolutionIterative:
    def myPow(self, x: float, n: int) -> float:
        # 迭代快速幂：将 n 的二进制逐位处理
        # 例如 x^10, 10=1010₂: x² × x⁸ = x^10
        if n < 0:
            x = 1 / x
            n = -n

        ans = 1.0
        x_contribution = x  # 当前位对应的 x 的幂次贡献
        while n > 0:
            if n % 2 == 1:
                # 当前二进制位为 1，将贡献乘入结果
                ans *= x_contribution
            # 每移一位，贡献平方（x → x² → x⁴ → x⁸ → ...）
            x_contribution *= x_contribution
            n //= 2

        return ans
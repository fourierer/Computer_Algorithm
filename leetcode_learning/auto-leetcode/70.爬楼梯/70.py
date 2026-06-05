"""
70.爬楼梯
难度：简单
链接：https://leetcode.cn/problems/climbing-stairs/
"""


class Solution:
    def climbStairs(self, n: int) -> int:
        # 动态规划：dp[i] 表示爬到第 i 阶的方法数
        # 到达第 i 阶有两种来源：从第 i-1 阶爬 1 步，或从第 i-2 阶爬 2 步
        # 因此 dp[i] = dp[i-1] + dp[i-2]，本质是斐波那契数列
        if n == 1:
            return 1

        dp = [0] * n
        # 边界条件：第 1 阶只有 1 种方法，第 2 阶有 2 种方法
        dp[0] = 1
        dp[1] = 2
        for i in range(2, n):
            dp[i] = dp[i - 1] + dp[i - 2]

        return dp[n - 1]


class SolutionOptimized:
    def climbStairs(self, n: int) -> int:
        # 空间优化：dp[i] 只依赖 dp[i-1] 和 dp[i-2]，用两个变量滚动
        if n == 1:
            return 1

        a, b = 1, 2  # a=dp[1], b=dp[2]
        for _ in range(2, n):
            a, b = b, a + b  # 滚动更新：a=dp[i-1], b=dp[i]

        return b
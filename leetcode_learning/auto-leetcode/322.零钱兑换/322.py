"""
322.零钱兑换
难度：中等
链接：https://leetcode.cn/problems/coin-change/
"""
from typing import List


class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        # dp[i] 表示凑成金额 i 所需的最少硬币数
        # 初始化为 amount+1（不可能达到的值，相当于无穷大）
        # 因为最多只用 amount 个面值为 1 的硬币，amount+1 一定比任何合法答案都大
        dp = [amount + 1] * (amount + 1)
        # 金额为 0 不需要任何硬币
        dp[0] = 0

        for i in range(1, amount + 1):
            for coin in coins:
                # 只有当前硬币面值不超过目标金额 i 时才能使用
                if coin <= i:
                    # dp[i - coin] + 1：使用当前硬币后，还需要的最少硬币数 + 1
                    # dp[i]：不使用当前硬币的情况
                    dp[i] = min(dp[i], dp[i - coin] + 1)

        # dp[amount] > amount 说明无法凑出目标金额，返回 -1
        return -1 if dp[amount] > amount else dp[amount]
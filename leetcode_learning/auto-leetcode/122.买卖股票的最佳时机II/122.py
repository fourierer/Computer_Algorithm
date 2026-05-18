"""
122.买卖股票的最佳时机II
难度：中等
链接：https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/
"""


class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        # 贪心：所有上涨段的涨幅之和就是最大利润
        profit = 0
        for i in range(1, len(prices)):
            if prices[i] > prices[i - 1]:
                profit += prices[i] - prices[i - 1]
        return profit


class SolutionDP:
    def maxProfit(self, prices: list[int]) -> int:
        # 动态规划：持有/不持有两个状态滚动
        cash = 0        # 不持有股票时的最大利润
        hold = -prices[0]  # 持有股票时的最大利润

        for price in prices[1:]:
            cash = max(cash, hold + price)    # 卖出 or 继续空仓
            hold = max(hold, cash - price)    # 买入 or 继续持有

        return cash
"""
121.买卖股票的最佳时机
难度：简单
链接：https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/
"""


class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        min_price = prices[0]  # 到当前位置为止的最低买入价
        max_profit = 0         # 最大利润

        for price in prices[1:]:
            # 今天卖出的利润 vs 之前最大利润
            max_profit = max(max_profit, price - min_price)
            # 更新历史最低买入价
            min_price = min(min_price, price)

        return max_profit
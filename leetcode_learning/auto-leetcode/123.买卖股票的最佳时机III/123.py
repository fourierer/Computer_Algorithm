"""
123.买卖股票的最佳时机III
难度：困难
链接：https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/
"""
from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # 状态定义：用 4 个变量分别表示 4 个阶段的最大利润
        # buy1  := 只完成"第1次买入"后的最大利润（负数，因为花了钱）
        # sell1 := 完成"第1次卖出"后的最大利润（即第1笔交易的净收益）
        # buy2  := 完成"第1次卖出 + 第2次买入"后的最大利润
        # sell2 := 完成"第2次卖出"后的最大利润（即两笔交易总净收益）

        n = len(prices)
        # 第 0 天初始化：买入则花费 prices[0]，卖出则利润为 0
        buy1 = buy2 = -prices[0]
        sell1 = sell2 = 0

        for i in range(1, n):
            # 第1次买入：要么之前已经买了（buy1），要么今天才买（-prices[i]）
            buy1 = max(buy1, -prices[i])
            # 第1次卖出：要么之前已经卖了（sell1），要么今天卖（buy1 + prices[i]）
            sell1 = max(sell1, buy1 + prices[i])
            # 第2次买入：要么之前已经第二次买了（buy2），要么今天第二次买（sell1 - prices[i]）
            buy2 = max(buy2, sell1 - prices[i])
            # 第2次卖出：要么之前已经第二次卖了（sell2），要么今天第二次卖（buy2 + prices[i]）
            sell2 = max(sell2, buy2 + prices[i])

        # 最多两笔交易的最大利润
        return sell2
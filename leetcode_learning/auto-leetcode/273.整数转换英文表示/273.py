"""
273.整数转换英文表示
难度：困难
链接：https://leetcode.cn/problems/integer-to-english-words/
"""


class Solution:
    def numberToWords(self, num: int) -> str:
        if num == 0:
            return "Zero"

        ONES = ["", "One", "Two", "Three", "Four", "Five", "Six",
                "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve",
                "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen",
                "Eighteen", "Nineteen"]
        TENS = ["", "", "Twenty", "Thirty", "Forty", "Fifty",
                "Sixty", "Seventy", "Eighty", "Ninety"]
        THOUSANDS = ["", "Thousand", "Million", "Billion"]

        def helper(n):
            """处理 < 1000 的三位数，返回英文"""
            if n == 0:
                return ""
            elif n < 20:
                return ONES[n] + " "
            elif n < 100:
                return TENS[n // 10] + " " + helper(n % 10)
            else:
                return ONES[n // 100] + " Hundred " + helper(n % 100)

        res = ""
        i = 0  # 当前是第几组（0=个, 1=千, 2=百万, 3=十亿）
        while num > 0:
            # 每 3 位一组处理
            if num % 1000 != 0:
                res = helper(num % 1000) + THOUSANDS[i] + " " + res
            num //= 1000
            i += 1

        return res.strip()

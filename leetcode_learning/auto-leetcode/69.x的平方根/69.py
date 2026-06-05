"""
69.x的平方根
难度：简单
链接：https://leetcode.cn/problems/sqrtx/
"""


class Solution:
    def mySqrt(self, x: int) -> int:
        # 牛顿迭代法：求 t² - x = 0 的正根
        # 迭代公式：t_{i+1} = (t_i + x / t_i) / 2
        # 即从当前猜测值出发，用切线与 x 轴的交点作为下一个猜测值
        if x == 0:
            return 0

        C, x0 = float(x), float(x)
        while True:
            # 牛顿迭代：取当前猜测值与 C/x0 的均值，逐步逼近 √C
            xi = 0.5 * (x0 + C / x0)
            # 收敛条件：两次迭代结果差值足够小
            if abs(x0 - xi) < 1e-5:
                break
            x0 = xi

        return int(x0)


class SolutionBinarySearch:
    def mySqrt(self, x: int) -> int:
        # 二分查找：在 [0, x] 中找最大的 mid 使得 mid² <= x
        if x == 0:
            return 0

        left, right = 0, x
        ans = 0
        while left <= right:
            mid = left + (right - left) // 2
            if mid * mid <= x:
                # mid² <= x，mid 是候选答案，尝试找更大的
                ans = mid
                left = mid + 1
            else:
                # mid² > x，mid 太大，缩小右边界
                right = mid - 1

        return ans
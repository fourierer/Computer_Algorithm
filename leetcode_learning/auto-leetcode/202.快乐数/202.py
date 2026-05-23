"""
202.快乐数
难度：简单
链接：https://leetcode.cn/problems/happy-number/
"""


class Solution:
    def isHappy(self, n: int) -> bool:

        def get_next(n):
            total_sum = 0
            while n > 0:
                n, digit = divmod(n, 10)
                total_sum += digit ** 2
            return total_sum

        seen = set()
        while n != 1 and n not in seen:
            seen.add(n)
            n = get_next(n)

        return n == 1


if __name__ == "__main__":
    sol = Solution()
    assert sol.isHappy(19) == True
    assert sol.isHappy(2) == False
    assert sol.isHappy(1) == True
    assert sol.isHappy(7) == True
"""
189.轮转数组
难度：中等
链接：https://leetcode.cn/problems/rotate-array/
"""
from math import gcd


class Solution:
    def rotate(self, nums: list[int], k: int) -> None:
        # 三次翻转法：整体翻转 → 翻转前k个 → 翻转后n-k个
        n = len(nums)
        k %= n

        self._reverse(nums, 0, n - 1)   # [1,2,3,4,5,6,7] → [7,6,5,4,3,2,1]
        self._reverse(nums, 0, k - 1)   # [7,6,5,4,3,2,1] → [5,6,7,4,3,2,1]
        self._reverse(nums, k, n - 1)   # [5,6,7,4,3,2,1] → [5,6,7,1,2,3,4]

    def _reverse(self, nums: list[int], left: int, right: int) -> None:
        while left < right:
            nums[left], nums[right] = nums[right], nums[left]
            left += 1
            right -= 1


class SolutionExtra:
    def rotate(self, nums: list[int], k: int) -> None:
        # 额外数组：直接放到目标位置
        n = len(nums)
        k %= n
        tmp = [0] * n
        for i in range(n):
            tmp[(i + k) % n] = nums[i]
        nums[:] = tmp


class SolutionCycle:
    def rotate(self, nums: list[int], k: int) -> None:
        # 环状替换：每个元素直接移到目标位置，gcd(n,k)个环
        n = len(nums)
        k %= n
        count = gcd(n, k)

        for start in range(count):
            cur = start
            prev = nums[start]
            while True:
                nxt = (cur + k) % n
                nums[nxt], prev = prev, nums[nxt]
                cur = nxt
                if cur == start:
                    break
"""
136.只出现一次的数字
难度：简单
链接：https://leetcode.cn/problems/single-number/
"""
from functools import reduce
from typing import List


class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        # 异或性质：a ^ a = 0，a ^ 0 = a，满足交换律和结合律
        # 所有数异或起来，出现两次的数互相抵消为 0，剩下的就是只出现一次的数
        # reduce 对数组连续异或：(a ^ b) ^ c ^ d ^ ...
        return reduce(lambda x, y: x ^ y, nums)


class SolutionLoop:
    def singleNumber(self, nums: List[int]) -> int:
        # 手动遍历异或，逻辑更直观
        # 任何数与 0 异或结果不变，初始化 res = 0
        res = 0
        for num in nums:
            # 相同数异或抵消为 0，不同数异或保留差异
            res ^= num
        return res
"""
167.两数之和II-输入有序数组
难度：中等
链接：https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/
"""
from typing import List


class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        low, high = 0, len(numbers) - 1

        while low < high:
            total = numbers[low] + numbers[high]
            if total == target:
                # 注意题目要求索引从1开始，所以需要+1
                return [low + 1, high + 1]
            elif total < target:
                low += 1
            else:
                high -= 1

        return [-1, -1]
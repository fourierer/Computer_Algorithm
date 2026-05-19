"""
238.除自身以外数组的乘积
难度：中等
链接：https://leetcode.cn/problems/product-of-array-except-self/
"""
from typing import List


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        length = len(nums)
        answer = [0] * length

        # 第一步：answer[i] 表示索引 i 左侧所有元素的乘积
        # 索引 0 左侧没有元素，所以 answer[0] = 1
        answer[0] = 1
        for i in range(1, length):
            answer[i] = nums[i - 1] * answer[i - 1]

        # 第二步：R 为右侧所有元素的乘积
        # 刚开始右边没有元素，所以 R = 1
        R = 1
        for i in range(length - 1, -1, -1):
            # 左乘积 answer[i] × 右乘积 R
            answer[i] = answer[i] * R
            # R 需要包含右边所有的乘积，计算下一个结果时要乘上当前值
            R *= nums[i]

        return answer


class SolutionExtraSpace:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        length = len(nums)

        # L 和 R 分别表示左右两侧的乘积列表
        L, R, answer = [0] * length, [0] * length, [0] * length

        # L[i] 为索引 i 左侧所有元素的乘积
        # 对于索引 0 的元素，左侧没有元素，所以 L[0] = 1
        L[0] = 1
        for i in range(1, length):
            L[i] = nums[i - 1] * L[i - 1]

        # R[i] 为索引 i 右侧所有元素的乘积
        # 对于索引 length-1 的元素，右侧没有元素，所以 R[length-1] = 1
        R[length - 1] = 1
        for i in range(length - 2, -1, -1):
            R[i] = nums[i + 1] * R[i + 1]

        # 除 nums[i] 之外其余各元素的乘积 = 左侧乘积 × 右侧乘积
        for i in range(length):
            answer[i] = L[i] * R[i]

        return answer
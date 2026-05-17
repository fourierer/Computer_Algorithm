"""
169.多数元素
难度：简单
链接：https://leetcode.cn/problems/majority-element/
"""


class Solution:
    def majorityElement(self, nums: list[int]) -> int:
        # Boyer-Moore 投票算法
        candidate = nums[0]
        count = 0

        for num in nums:
            if count == 0:
                # 票数归零，更换候选人
                candidate = num
                count = 1
            elif num == candidate:
                count += 1
            else:
                count -= 1

        return candidate


class SolutionHash:
    def majorityElement(self, nums: list[int]) -> int:
        from collections import Counter
        threshold = len(nums) // 2
        counter = Counter(nums)
        for num, cnt in counter.items():
            if cnt > threshold:
                return num


class SolutionSort:
    def majorityElement(self, nums: list[int]) -> int:
        # 多数元素数量超过 n/2，排序后一定在中间位置
        nums.sort()
        return nums[len(nums) // 2]
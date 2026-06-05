"""
33.搜索旋转排序数组
难度：中等
链接：https://leetcode.cn/problems/search-in-rotated-sorted-array/
"""
from typing import List


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        # 二分查找：旋转数组从中间切开，必有一半是有序的
        # 判断哪一半有序，再判断 target 是否在有序半边内，缩小范围
        left, right = 0, len(nums) - 1

        while left <= right:
            mid = left + (right - left) // 2

            if nums[mid] == target:
                return mid

            if nums[left] <= nums[mid]:
                # 左半边 [left, mid] 有序
                if nums[left] <= target < nums[mid]:
                    # target 在左半边范围内，搜索左半边
                    right = mid - 1
                else:
                    # target 不在左半边，搜索右半边
                    left = mid + 1
            else:
                # 右半边 [mid, right] 有序
                if nums[mid] < target <= nums[right]:
                    # target 在右半边范围内，搜索右半边
                    left = mid + 1
                else:
                    # target 不在右半边，搜索左半边
                    right = mid - 1

        return -1
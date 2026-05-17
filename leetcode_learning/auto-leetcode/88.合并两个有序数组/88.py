"""
88.合并两个有序数组
难度：简单
链接：https://leetcode.cn/problems/merge-sorted-array/
"""

class Solution:
    def merge(self, nums1: list[int], m: int, nums2: list[int], n: int) -> None:
        # 从后往前填充，避免覆盖 nums1 中未处理的元素
        i, j, k = m - 1, n - 1, m + n - 1

        while i >= 0 and j >= 0:
            if nums1[i] > nums2[j]:
                nums1[k] = nums1[i]
                i -= 1
            else:
                nums1[k] = nums2[j]
                j -= 1
            k -= 1

        # nums2 剩余元素直接复制到 nums1 前部
        # nums1 剩余元素无需处理，已在正确位置
        while j >= 0:
            nums1[k] = nums2[j]
            j -= 1
            k -= 1
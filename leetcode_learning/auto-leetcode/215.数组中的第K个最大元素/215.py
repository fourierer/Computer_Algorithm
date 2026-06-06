"""
215.数组中的第K个最大元素
难度：中等
链接：https://leetcode.cn/problems/kth-largest-element-in-an-array/
"""
import heapq
from typing import List


class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        # 快速选择：基于 partition，平均 O(n)
        # partition 后 pivot 归位到 mid，右侧比 pivot 大
        # 用 length_of_right 表示 pivot 右侧的元素个数
        # 若 length_of_right == k-1，说明 pivot 就是第 k 大
        # 若 length_of_right > k-1，说明第 k 大在右侧
        # 若 length_of_right < k-1，说明第 k 大在左侧，且需要减去右侧的元素个数

        def solve(start: int, end: int, k: int) -> int:
            mid = _divide(start, end)
            length_of_right = end - mid
            if length_of_right == k - 1:
                return nums[mid]
            elif length_of_right > k - 1:
                # 第 k 大在 pivot 右侧，k 不变
                return solve(mid + 1, end, k)
            else:
                # 第 k 大在 pivot 左侧，需要减去右侧和 pivot 本身的个数
                return solve(start, mid - 1, k - length_of_right - 1)

        def _divide(start: int, end: int) -> int:
            if start >= end:
                return start

            # 左右指针交替扫描，与快速排序的 partition 一致
            i, j = start, end
            pivot = nums[i]

            while i < j:
                # 从右往左找第一个比 pivot 小的
                while nums[j] >= pivot and j > i:
                    j -= 1
                nums[i], nums[j] = nums[j], nums[i]

                # 从左往右找第一个比 pivot 大的
                while nums[i] <= pivot and i < j:
                    i += 1
                nums[i], nums[j] = nums[j], nums[i]

            # 此时 i == j，pivot 归位
            return i

        return solve(0, len(nums) - 1, k)


class SolutionHeap:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        # 小顶堆：维护大小为 k 的堆，堆顶即第 k 大
        heap = []
        for num in nums:
            if len(heap) < k:
                # 堆未满，直接入堆
                heapq.heappush(heap, num)
            elif num > heap[0]:
                # 当前元素比堆顶大，替换堆顶（弹出最小值，推入更大值）
                heapq.heapreplace(heap, num)
        # 堆顶就是第 k 大的元素
        return heap[0]
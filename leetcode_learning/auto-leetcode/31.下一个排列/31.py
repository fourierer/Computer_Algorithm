"""
31.下一个排列
难度：中等
链接：https://leetcode.cn/problems/next-permutation/
"""
from typing import List


class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        # 原地修改，返回 None
        n = len(nums)

        # 第一步：从右向左找第一个下降位置 i，使得 nums[i] < nums[i+1]
        # i 右侧（含 i+1）此时为降序，是该前缀下的最大排列
        i = n - 2
        while i >= 0 and nums[i] >= nums[i + 1]:
            i -= 1

        # 第二步：若存在下降点，在右侧降序段中找大于 nums[i] 的最小值
        # 降序段从右向左扫描，首个 > nums[i] 的即为所求（最小的大于 nums[i] 的元素）
        if i >= 0:
            j = n - 1
            while nums[j] <= nums[i]:
                j -= 1
            nums[i], nums[j] = nums[j], nums[i]

        # 第三步：翻转 i 右侧的降序段为升序，得到该前缀下的最小排列
        # i == -1（整体降序）时翻转整个数组，得到字典序最小的排列
        self._reverse(nums, i + 1, n - 1)

    def _reverse(self, nums: List[int], left: int, right: int) -> None:
        # 原地双指针翻转 [left, right]
        while left < right:
            nums[left], nums[right] = nums[right], nums[left]
            left += 1
            right -= 1

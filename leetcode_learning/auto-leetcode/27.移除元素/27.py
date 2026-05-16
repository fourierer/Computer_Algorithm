"""
27.移除元素
难度：简单
链接：https://leetcode.cn/problems/remove-element/
"""


class Solution:
    def removeElement(self, nums: list[int], val: int) -> int:
        slow = 0  # 慢指针：下一个保留元素应放的位置

        for fast in range(len(nums)):
            # 只有非 val 元素才保留到前面
            if nums[fast] != val:
                nums[slow] = nums[fast]
                slow += 1

        return slow


class Solution2:
    def removeElement(self, nums: list[int], val: int) -> int:
        # 左右指针：顺序可变时，用末尾元素覆盖 val，减少赋值次数
        left, right = 0, len(nums) - 1

        while left <= right:
            if nums[left] == val:
                nums[left] = nums[right]  # 用末尾元素覆盖
                right -= 1  # 末尾位置已用，右指针左移
            else:
                left += 1  # 当前元素保留，左指针右移

        return left
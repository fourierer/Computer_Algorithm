"""
27.移除元素
难度：简单
链接：https://leetcode.cn/problems/remove-element/
"""


class Solution:
    def removeElement(self, nums: list[int], val: int) -> int:
        slow = -1  # 慢指针：指向当前保留元素的末尾位置

        for fast in range(len(nums)):
            # 发现非 val 元素，保留到前面
            if nums[fast] != val:
                slow += 1  # 慢指针前进一步
                nums[slow] = nums[fast]  # 将新元素放到正确位置

        return slow + 1


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
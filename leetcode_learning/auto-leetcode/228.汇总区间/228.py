"""
228.汇总区间
难度：简单
链接：https://leetcode.cn/problems/summary-ranges/
"""

from typing import List


class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        if not nums:
            return []

        result = []
        start = nums[0]

        for i in range(1, len(nums)):
            # 当前数与前一个数不连续，输出上一个区间
            if nums[i] != nums[i - 1] + 1:
                if start == nums[i - 1]:
                    result.append(str(start))
                else:
                    result.append(f"{start}->{nums[i - 1]}")
                start = nums[i]

        # 循环只在连续中断时输出区间，末尾的连续序列不会触发中断，需要单独输出
        if start == nums[-1]:
            result.append(str(start))
        else:
            result.append(f"{start}->{nums[-1]}")

        return result


if __name__ == "__main__":
    sol = Solution()
    assert sol.summaryRanges([0, 1, 2, 4, 5, 7]) == ["0->2", "4->5", "7"]
    assert sol.summaryRanges([0, 2, 3, 4, 6, 8, 9]) == ["0", "2->4", "6", "8->9"]
    assert sol.summaryRanges([]) == []
    assert sol.summaryRanges([1]) == ["1"]
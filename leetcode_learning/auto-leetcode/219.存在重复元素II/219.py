"""
219.存在重复元素II
难度：简单
链接：https://leetcode.cn/problems/contains-duplicate-ii/
"""

from typing import List


class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        index_dict = {}
        for i in range(len(nums)):
            if nums[i] in index_dict and (i - index_dict[nums[i]]) <= k:
                return True
            index_dict[nums[i]] = i
        return False


if __name__ == "__main__":
    sol = Solution()
    assert sol.containsNearbyDuplicate([1, 2, 3, 1], 3) == True
    assert sol.containsNearbyDuplicate([1, 0, 1, 1], 1) == True
    assert sol.containsNearbyDuplicate([1, 2, 3, 1, 2, 3], 2) == False
    assert sol.containsNearbyDuplicate([1], 0) == False
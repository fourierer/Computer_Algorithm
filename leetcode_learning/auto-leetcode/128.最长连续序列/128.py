"""
128.最长连续序列
难度：中等
链接：https://leetcode.cn/problems/longest-consecutive-sequence/
"""


class Solution:
    def longestConsecutive(self, nums: list[int]) -> int:
        num_set = set(nums)
        longest = 0

        for num in num_set:
            # 只有当 num-1 不在集合中时，num 才是一个连续序列的起点
            if num - 1 not in num_set:
                current_num = num
                current_streak = 1

                while current_num + 1 in num_set:
                    current_num += 1
                    current_streak += 1

                longest = max(longest, current_streak)

        return longest


if __name__ == "__main__":
    sol = Solution()
    assert sol.longestConsecutive([100, 4, 200, 1, 3, 2]) == 4
    assert sol.longestConsecutive([0, 3, 7, 2, 5, 8, 4, 6, 0, 1]) == 9
    assert sol.longestConsecutive([1, 0, 1, 2]) == 3
    assert sol.longestConsecutive([]) == 0
    assert sol.longestConsecutive([1]) == 1
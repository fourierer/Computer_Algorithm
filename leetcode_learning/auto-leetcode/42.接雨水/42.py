"""
42.接雨水
难度：困难
链接：https://leetcode.cn/problems/trapping-rain-water/
"""


class Solution:
    def trap(self, height: list[int]) -> int:
        # 双指针法：左右指针从两端向中间移动
        # 核心思想：雨水量由较小一侧的最大值决定
        left, right = 0, len(height) - 1
        left_max, right_max = 0, 0
        water = 0

        while left < right: # 不用取等号，因为左右指针最终汇聚的位置一定是数组最高点
            if height[left] < height[right]:
                # 左侧较矮，左侧最大值决定当前贡献
                if height[left] >= left_max:
                    left_max = height[left]
                else:
                    # 当前位置低于左侧最大值，可以接雨水
                    water += left_max - height[left]
                left += 1
            else:
                # 右侧较矮，右侧最大值决定当前贡献
                if height[right] >= right_max:
                    right_max = height[right]
                else:
                    water += right_max - height[right]
                right -= 1

        return water



    def trap_dp(self, height: list[int]) -> int:
        # 动态规划法：预处理每个位置的左右最高柱子
        # water[i] = min(left_max[i], right_max[i]) - height[i]
        n = len(height)
        if n == 0:
            return 0
        
        # 从左到右，记录每个位置左侧最大值（包含自身）
        left_max = [0] * n
        left_max[0] = height[0]
        for i in range(1, n):
            left_max[i] = max(left_max[i - 1], height[i])

        # 从右到左，记录每个位置右侧最大值（包含自身）
        right_max = [0] * n
        right_max[n - 1] = height[n - 1]
        for i in range(n - 2, -1, -1):
            right_max[i] = max(right_max[i + 1], height[i])

        # 逐个位置累加雨水量
        water = 0
        for i in range(n):
            water += min(left_max[i], right_max[i]) - height[i]

        return water


if __name__ == "__main__":
    s = Solution()
    test_cases = [
        ([0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1], 6),
        ([4, 2, 0, 3, 2, 5], 9),
        ([], 0),
        ([1], 0),
        ([1, 0, 1], 1),
        ([3, 0, 0, 2, 0, 4], 10),
        ([5, 4, 1, 2], 1),
    ]

    for i, (height, expected) in enumerate(test_cases, 1):
        result1 = s.trap(height)
        result2 = s.trap_dp(height)
        assert result1 == expected, f"用例{i}双指针失败: 期望{expected}, 得到{result1}"
        assert result2 == expected, f"用例{i}动态规划失败: 期望{expected}, 得到{result2}"
        print(f"用例{i}: height={height} => {result1} ✓")
"""
344.反转字符串
难度：简单
链接：https://leetcode.cn/problems/reverse-string/
"""
from typing import List


class Solution:
    def reverseString(self, s: List[str]) -> None:
        # 双指针：左右向中间靠拢，交换所指元素
        left, right = 0, len(s) - 1
        while left < right:
            s[left], s[right] = s[right], s[left]
            left += 1
            right -= 1


class SolutionXOR:
    def reverseString(self, s: List[str]) -> None:
        # 异或交换：不用临时变量
        # a ^= b → b ^= a → a ^= b 完成交换
        # 注意：Python 中字符串不可直接异或，需转 ord 再转回 chr
        left, right = 0, len(s) - 1
        while left < right:
            a, b = ord(s[left]), ord(s[right])
            a ^= b
            b ^= a
            a ^= b
            s[left], s[right] = chr(a), chr(b)
            left += 1
            right -= 1


if __name__ == "__main__":
    # 测试
    def test(s_list, expected):
        sol = Solution()
        s = s_list[:]
        sol.reverseString(s)
        assert s == expected, f"FAIL: {s_list} -> {s}, expected {expected}"

    test(["h", "e", "l", "l", "o"], ["o", "l", "l", "e", "h"])
    test(["H", "a", "n", "n", "a", "h"], ["h", "a", "n", "n", "a", "H"])
    test(["a"], ["a"])
    test(["a", "b"], ["b", "a"])
    test([], [])

    # 异或版测试
    def test_xor(s_list, expected):
        sol = SolutionXOR()
        s = s_list[:]
        sol.reverseString(s)
        assert s == expected, f"FAIL: {s_list} -> {s}, expected {expected}"

    test_xor(["h", "e", "l", "l", "o"], ["o", "l", "l", "e", "h"])
    test_xor(["a", "b"], ["b", "a"])

    print("ALL OK")

"""
541.反转字符串II
难度：简单
链接：https://leetcode.cn/problems/reverse-string-ii/
"""


class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        a = list(s)
        n = len(a)
        # 每 2k 个一组，反转前 k 个
        for i in range(0, n, 2 * k):
            # 切片自动处理越界：剩余不足 k 个时反转到末尾
            # right 取 min(i+k-1, n-1) 防止越界
            self.reverse(a, i, min(i + k - 1, n - 1))
        return ''.join(a)

    def reverse(self, s, left, right):
        while left < right:
            s[left], s[right] = s[right], s[left]
            left += 1
            right -= 1

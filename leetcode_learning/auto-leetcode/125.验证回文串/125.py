"""
125.验证回文串
难度：简单
链接：https://leetcode.cn/problems/valid-palindrome/
"""


class Solution:
    def isPalindrome(self, s: str) -> bool:
        result = []
        for ch in s:
            # 判断是否为字母或者数字
            if ch.isalnum():
                result.append(ch.lower())
        return result == result[::-1]

    def isPalindrome_two_pointer(self, s: str) -> bool:
        # 双指针：从两端向中间比较，O(1) 额外空间
        left, right = 0, len(s) - 1
        while left < right:
            # 跳过左端非字母数字字符
            while left < right and not s[left].isalnum():
                left += 1
            # 跳过右端非字母数字字符
            while left < right and not s[right].isalnum():
                right -= 1
            # 比较字符小写形式
            if s[left].lower() != s[right].lower():
                return False
            left += 1
            right -= 1
        return True
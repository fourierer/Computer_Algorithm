"""
917.仅仅反转字母
难度：简单
链接：https://leetcode.cn/problems/reverse-only-letters/
"""


class Solution:
    def reverseOnlyLetters(self, s: str) -> str:
        # Python 字符串是不可变对象（immutable），无法 s[i] = x 直接修改某一位
        # 必须转成 list 才能通过下标交换，最后 ''.join 拼回字符串
        # 这是 Python 处理字符串原地修改题的通用模式
        a = list(s)
        left, right = 0, len(a) - 1
        while left < right:
            # 左指针跳过非字母（独立 while，可连续移动）
            while left < right and not a[left].isalpha():
                left += 1
            # 右指针跳过非字母（独立 while，可连续移动）
            while left < right and not a[right].isalpha():
                right -= 1
            # 两个都是字母，交换
            a[left], a[right] = a[right], a[left]
            left += 1
            right -= 1
        return ''.join(a)

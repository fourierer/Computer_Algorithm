"""
844.比较含退格的字符串
难度：简单
链接：https://leetcode.cn/problems/backspace-string-compare/
"""


class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        # 栈模拟：遇 # 弹栈（删除前一个字符），否则入栈
        # 退格键 # 的本质就是"撤销上一个字符"，与栈的弹出操作天然对应
        # 最后比较两串处理后的栈内容是否相同
        def build(string):
            stack = []
            for c in string:
                if c == '#':
                    if stack:
                        stack.pop()
                else:
                    stack.append(c)
            return stack

        return build(s) == build(t)


class SolutionTwoPointer:
    def backspaceCompare(self, s: str, t: str) -> bool:
        # 双指针逆序：O(1) 空间，从末尾向前处理
        # # 影响的是前面的字符，所以从后往前可以"预知"退格数
        i, j = len(s) - 1, len(t) - 1
        skip_i, skip_j = 0, 0

        while i >= 0 or j >= 0:
            # 在 s 中找到下一个有效字符
            while i >= 0:
                if s[i] == '#':
                    skip_i += 1
                    i -= 1
                elif skip_i > 0:
                    skip_i -= 1
                    i -= 1
                else:
                    break
            # 在 t 中找到下一个有效字符
            while j >= 0:
                if t[j] == '#':
                    skip_j += 1
                    j -= 1
                elif skip_j > 0:
                    skip_j -= 1
                    j -= 1
                else:
                    break
            # 比较当前有效字符
            if i >= 0 and j >= 0:
                if s[i] != t[j]:
                    return False
            elif i >= 0 or j >= 0:
                # 一个还有有效字符，另一个已经没有
                return False
            i -= 1
            j -= 1

        return True
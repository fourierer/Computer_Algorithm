"""
150.逆波兰表达式求值
难度：中等
链接：https://leetcode.cn/problems/evaluate-reverse-polish-notation/
"""

from typing import List


class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []

        for token in tokens:
            if token in {"+", "-", "*", "/"}:
                # 先弹出的是右操作数，后弹出的是左操作数
                b = stack.pop()
                a = stack.pop()
                if token == "+":
                    stack.append(a + b)
                elif token == "-":
                    stack.append(a - b)
                elif token == "*":
                    stack.append(a * b)
                else:
                    # 除法向零截断，用 int(a/b) 而非 a//b
                    # int(a/b) 向零截断：int(-13/5) = -2
                    # a//b 向负无穷取整：-13//5 = -3
                    stack.append(int(a / b))
            else:
                stack.append(int(token))

        return stack[0]


if __name__ == "__main__":
    sol = Solution()
    assert sol.evalRPN(["2", "1", "+", "3", "*"]) == 9
    assert sol.evalRPN(["4", "13", "5", "/", "+"]) == 6
    assert sol.evalRPN(["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]) == 22
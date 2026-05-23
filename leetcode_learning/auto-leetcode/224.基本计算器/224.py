"""
224.基本计算器
难度：困难
链接：https://leetcode.cn/problems/basic-calculator/
"""


class Solution:
    def calculate(self, s: str) -> int:
        result = 0
        sign = 1  # 当前数字的符号，1为正，-1为负
        # 栈记录括号导致的符号翻转，初始为1表示无括号影响
        sign_stack = [1]

        i = 0
        while i < len(s):
            ch = s[i]
            if ch.isdigit():
                # 解析完整数字
                num = 0
                while i < len(s) and s[i].isdigit():
                    num = num * 10 + int(s[i])
                    i += 1
                result += sign * num
                continue
            elif ch == "+":
                # +号取当前括号层的符号
                sign = sign_stack[-1]
            elif ch == "-":
                # -号取当前括号层符号的相反数，实现一元负号和括号翻转
                sign = -sign_stack[-1]
            elif ch == "(":
                # 左括号前的运算符决定了括号内的基础符号，压栈
                sign_stack.append(sign)
            elif ch == ")":
                # 右括号弹出，恢复外层符号
                sign_stack.pop()

            i += 1

        return result


if __name__ == "__main__":
    sol = Solution()
    assert sol.calculate("1 + 1") == 2
    assert sol.calculate(" 2-1 + 2 ") == 3
    assert sol.calculate("(1+(4+5+2)-3)+(6+8)") == 23
    assert sol.calculate("-(2+3)") == -5
    assert sol.calculate("1-(     -2)") == 3
"""
20.有效的括号
难度：简单
链接：https://leetcode.cn/problems/valid-parentheses/
"""


class Solution:
    def isValid(self, s: str) -> bool:
        # 栈解法：左括号入栈，右括号与栈顶匹配
        pairs = {')': '(', ']': '[', '}': '{'}
        stack = []

        for ch in s:
            if ch in pairs.values():
                # 左括号入栈
                stack.append(ch)
            else:
                # 右括号必须与栈顶匹配
                if not stack or stack[-1] != pairs[ch]:
                    return False
                stack.pop()
        # 遍历结束后，栈为空则有效
        return not stack

    def isValid_early(self, s: str) -> bool:
        # 奇数长度直接返回 False，提前剪枝
        if len(s) % 2 == 1:
            return False

        pairs = {')': '(', ']': '[', '}': '{'}
        stack = []

        for ch in s:
            if ch in pairs.values():
                stack.append(ch)
            else:
                if not stack or stack[-1] != pairs[ch]:
                    return False
                stack.pop()

        return not stack


if __name__ == "__main__":
    sol = Solution()
    test_cases = [
        ("()", True),
        ("()[]{}", True),
        ("(]", False),
        ("([])", True),
        ("", True),
        ("([)]", False),
        ("{[]}", True),
        ("(((", False),
        (")))", False),
        ("({[]})", True),
        ("(", False),
        (")", False),
    ]

    for i, (s, expected) in enumerate(test_cases, 1):
        r1 = sol.isValid(s)
        r2 = sol.isValid_early(s)
        assert r1 == expected, f"用例{i}栈解法失败: 输入'{s}', 期望{expected}, 得到{r1}"
        assert r2 == expected, f"用例{i}剪枝解法失败: 输入'{s}', 期望{expected}, 得到{r2}"
        print(f"用例{i}: '{s}' => {r1} ✓")
"""
155.最小栈
难度：中等
链接：https://leetcode.cn/problems/min-stack/
"""


class MinStack:

    def __init__(self):
        self.stack = []
        self.min_stack = []

    def push(self, val: int) -> None:
        self.stack.append(val)
        # 辅助栈压入到该位置为止的最小值，而非全局最小值
        # 例如 push(-2)->min_stack=[-2], push(0)->min_stack=[-2,-2], push(-3)->min_stack=[-2,-2,-3]
        if self.min_stack:
            self.min_stack.append(min(val, self.min_stack[-1]))
        else:
            self.min_stack.append(val)

    def pop(self) -> None:
        # 两个栈必须同步弹出
        # min_stack 与 stack 一一对应，min_stack[i] 记录的是 stack[0..i] 的最小值
        # 若只弹 stack 不弹 min_stack，被弹出的元素对应的旧最小值仍留在 min_stack 栈顶，getMin 就会出错
        self.stack.pop()
        self.min_stack.pop()

    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return self.min_stack[-1]


if __name__ == "__main__":
    min_stack = MinStack()
    min_stack.push(-2)
    min_stack.push(0)
    min_stack.push(-3)
    assert min_stack.getMin() == -3
    min_stack.pop()
    assert min_stack.top() == 0
    assert min_stack.getMin() == -2
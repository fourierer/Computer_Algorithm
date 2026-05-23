"""
71.简化路径
难度：中等
链接：https://leetcode.cn/problems/simplify-path/
"""


class Solution:
    def simplifyPath(self, path: str) -> str:
        stack = []
        # 按 / 分割路径，处理多个连续斜杠
        parts = path.split("/")

        for part in parts:
            if part == "" or part == ".":
                # 空串（连续斜杠产生）或当前目录，忽略
                continue
            elif part == "..":
                # 返回上级目录，栈非空时才弹出
                if stack:
                    stack.pop()
            else:
                # 有效的目录名，入栈
                stack.append(part)

        # 拼接结果，根路径以 / 开头
        return "/" + "/".join(stack)


if __name__ == "__main__":
    sol = Solution()
    assert sol.simplifyPath("/home/") == "/home"
    assert sol.simplifyPath("/../") == "/"
    assert sol.simplifyPath("/home//foo/") == "/home/foo"
    assert sol.simplifyPath("/a/./b/../../c/") == "/c"
    assert sol.simplifyPath("/a/../../b/../c//.//") == "/c"
    assert sol.simplifyPath("/") == "/"
    assert sol.simplifyPath("/...") == "/..."
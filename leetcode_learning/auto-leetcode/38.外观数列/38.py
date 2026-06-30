"""
38.外观数列
难度：中等
链接：https://leetcode.cn/problems/count-and-say/
"""


class Solution:
    def countAndSay(self, n: int) -> str:
        # 从 "1" 开始迭代 n-1 次，每次描述前一项
        s = "1"
        for _ in range(n - 1):
            s = self._describe(s)
        return s

    def _describe(self, s: str) -> str:
        # 用 cur_char + cur_count 统计连续相同字符，描述成 "计数+字符" 的拼接
        # 与 443.压缩字符串 的核心逻辑一致：遍历统计连续段，遇不同字符则输出一段
        result = []
        cur_char = s[0]
        cur_count = 1
        for i in range(1, len(s)):
            if s[i] == cur_char:
                cur_count += 1
            else:
                # 一段结束：输出 "计数+字符"（外观数列要求统一写计数，含长度1）
                result.append(str(cur_count) + cur_char)
                cur_char = s[i]
                cur_count = 1
        # 别忘了最后一段
        result.append(str(cur_count) + cur_char)
        return ''.join(result)


class SolutionTwoPointer:
    def countAndSay(self, n: int) -> str:
        # 从 "1" 开始迭代 n-1 次，每次描述前一项
        s = "1"
        for _ in range(n - 1):
            # 双指针统计连续相同字符
            res = []
            i = 0
            while i < len(s):
                count = 1
                # 向右扩展连续相同字符
                while i + 1 < len(s) and s[i] == s[i + 1]:
                    count += 1
                    i += 1
                # 描述：count 个 s[i]
                res.append(str(count) + s[i])
                i += 1
            s = ''.join(res)
        return s

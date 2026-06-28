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

"""
1209.删除字符串中的所有相邻重复项II
难度：中等
链接：https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string-ii/
"""


class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
        # 栈存储 (字符, 连续计数)：一次遍历完成删除
        # 栈顶字符与当前相同则计数+1，达到 k 则弹栈（删除 k 个）
        # 注：题目"恰好 k 个连续相同"是指每次删除时选中 k 个，而非"总共只有 k 个才删"
        # 即使字符连续出现 k+1 次甚至更多，也是合法的删除操作：
        #   从中任选 k 个（它们本身就是"k 个连续且相同"）删除，剩 1 个
        #   因字符相同，删哪 k 个结果都一样，栈累计到 k 就删与之等价
        #   如 "aaaa"(k=2): a→a→pop→a→a→pop → ""，暴力 aaaa→aa→"" 一致
        stack = []  # 元素为 [char, count]

        for c in s:
            if stack and stack[-1][0] == c:
                stack[-1][1] += 1
                # 连续计数达到 k，删除这 k 个字符
                if stack[-1][1] == k:
                    stack.pop()
            else:
                stack.append([c, 1])

        # 拼接结果：每个字符重复其连续计数次
        return ''.join(char * count for char, count in stack)

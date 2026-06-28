"""
459.重复的子字符串
难度：中等
链接：https://leetcode.cn/problems/repeated-substring-pattern/
"""


class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        # 经典 trick：若 s 由子串重复构成，则 s 是 (s+s)[1:-1] 的子串
        # 去掉首尾各一个字符，避免直接匹配到原始的 s
        #
        # 证明（设 s 长度 n，由子串 p 长度 m 重复 k≥2 次构成，s = p^k）：
        #
        # 必要性（可重复 → 能匹配）：
        #   s+s = p^{2k}，去掉首尾各一字符后，因 p 的周期性，从位置 m 起存在完整的 s
        #   如 s="abab"(p="ab",k=2)：s+s="abababab" → t="bababa" → "abab" 从索引2完整出现
        #
        # 充分性（能匹配 → 可重复）：
        #   s in t 意味着 s 与自身错位 i(1≤i≤n-1) 后重合 → s 有周期 i 且 i 整除 n
        #   → s 由长度 i 的子串重复 n/i≥2 次构成
        #
        # 为何必须去掉首尾各一字符：
        #   不去掉的话 s+s 的前 n 个和后 n 个字符本身就是 s，s in s+s 恒为真
        #   去掉后匹配位置 i 被限制在 [1, n-1]，排除 i=0(平凡前缀) 和 i=n(平凡后缀)
        t = (s + s)[1:-1]
        return s in t


class SolutionKMP:
    def repeatedSubstringPattern(self, s: str) -> bool:
        # KMP next 数组法：next[i] 为 s[0..i] 的最长相等前后缀长度
        # 若 n % (n - next[-1] - 1) == 0 且 next[-1] > 0，则可由子串重复构成
        n = len(s)
        nxt = [0] * n
        j = 0
        for i in range(1, n):
            while j > 0 and s[i] != s[j]:
                j = nxt[j - 1]
            if s[i] == s[j]:
                j += 1
            nxt[i] = j
        # 最小循环节长度 = n - next[-1]
        return nxt[-1] > 0 and n % (n - nxt[-1]) == 0

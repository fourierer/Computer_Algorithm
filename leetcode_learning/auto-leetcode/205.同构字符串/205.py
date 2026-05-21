"""
205.同构字符串
难度：简单
链接：https://leetcode.cn/problems/isomorphic-strings/
"""


class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        # 双向映射，确保一一对应
        s2t = {}
        t2s = {}
        for ch_s, ch_t in zip(s, t):
            # s 中的字符已映射过，但映射目标不同
            if ch_s in s2t and s2t[ch_s] != ch_t:
                return False
            # t 中的字符已被其他字符映射
            if ch_t in t2s and t2s[ch_t] != ch_s:
                return False
            s2t[ch_s] = ch_t
            t2s[ch_t] = ch_s
        return True


if __name__ == "__main__":
    sol = Solution()
    assert sol.isIsomorphic("egg", "add") == True
    assert sol.isIsomorphic("foo", "bar") == False
    assert sol.isIsomorphic("paper", "title") == True
    assert sol.isIsomorphic("ab", "aa") == False
    assert sol.isIsomorphic("a", "b") == True
    assert sol.isIsomorphic("badc", "baba") == False
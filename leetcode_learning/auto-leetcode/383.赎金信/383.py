"""
383.赎金信
难度：简单
链接：https://leetcode.cn/problems/ransom-note/
"""


class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        # 统计 magazine 中各字符出现次数
        freq = {}
        for ch in magazine:
            freq[ch] = freq.get(ch, 0) + 1
        # 遍历 ransomNote，逐个消耗字符
        for ch in ransomNote:
            if freq.get(ch, 0) == 0:
                return False
            freq[ch] -= 1
        return True


if __name__ == "__main__":
    s = Solution()
    assert s.canConstruct("a", "b") == False
    assert s.canConstruct("aa", "ab") == False
    assert s.canConstruct("aa", "aab") == True
    assert s.canConstruct("", "abc") == True
    assert s.canConstruct("abc", "cba") == True
    assert s.canConstruct("aaa", "aaabbb") == True
    assert s.canConstruct("aaaa", "aaabbb") == False
    assert s.canConstruct("abcdef", "abc") == False
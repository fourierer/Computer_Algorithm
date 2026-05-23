"""
290.单词规律
难度：简单
链接：https://leetcode.cn/problems/word-pattern/
"""


class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        words = s.split()
        if len(pattern) != len(words):
            return False
        # 双向映射，确保一一对应
        p2w = {}
        w2p = {}
        for ch, word in zip(pattern, words):
            # 字符已映射但映射单词不同
            if ch in p2w and p2w[ch] != word:
                return False
            # 单词已映射但映射字符不同
            if word in w2p and w2p[word] != ch:
                return False
            p2w[ch] = word
            w2p[word] = ch
        return True


if __name__ == "__main__":
    sol = Solution()
    assert sol.wordPattern("abba", "dog cat cat dog") == True
    assert sol.wordPattern("abba", "dog cat cat fish") == False
    assert sol.wordPattern("aaaa", "dog dog dog dog") == True
    assert sol.wordPattern("abba", "dog dog dog dog") == False
    assert sol.wordPattern("abc", "dog cat fish") == True
    assert sol.wordPattern("ab", "dog") == False
    print("所有测试用例通过！")
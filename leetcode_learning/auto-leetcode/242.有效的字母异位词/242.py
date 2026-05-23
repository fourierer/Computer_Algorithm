"""
242.有效的字母异位词
难度：简单
链接：https://leetcode.cn/problems/valid-anagram/
"""


class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        # 统计s中各个字符的出现次数
        s_count = {}
        for ch in s:
            count_cur = s_count.get(ch, 0)
            s_count[ch] = count_cur + 1

        # 根据t中的字符来消除次数
        for ch in t:
            count_cur = s_count.get(ch, 0)
            if count_cur == 0:
                return False
            s_count[ch] -= 1

        # 最后检查s_count中是否有遗留的
        for key, value in s_count.items():
            if value > 0:
                return False

        return True


if __name__ == "__main__":
    sol = Solution()
    assert sol.isAnagram("anagram", "nagaram") == True
    assert sol.isAnagram("rat", "car") == False
    assert sol.isAnagram("a", "a") == True
    assert sol.isAnagram("ab", "ba") == True
    assert sol.isAnagram("ab", "ac") == False
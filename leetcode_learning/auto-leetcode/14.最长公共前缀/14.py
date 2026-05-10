"""
14.最长公共前缀
难度：简单
链接：https://leetcode.cn/problems/longest-common-prefix/
"""

class Solution:
    def longestCommonPrefix(self, strs: list[str]) -> str:
        # 纵向扫描：逐位比较所有字符串同一位置的字符
        if not strs:
            return ""

        first = strs[0]
        for i, ch in enumerate(first):
            # 检查其余字符串在位置 i 是否都有相同字符
            for s in strs[1:]:
                if i >= len(s) or s[i] != ch:
                    return first[:i]

        return first

    def longestCommonPrefix_horizontal(self, strs: list[str]) -> str:
        # 横向扫描：依次两两求公共前缀，逐步缩小范围
        if not strs:
            return ""

        prefix = strs[0]
        for s in strs[1:]:
            # 不断缩短 prefix 直到它是 s 的前缀
            while not s.startswith(prefix):
                prefix = prefix[:-1]
                if not prefix:
                    return ""

        return prefix


if __name__ == "__main__":
    s = Solution()
    test_cases = [
        (["flower", "flow", "flight"], "fl"),
        (["dog", "racecar", "car"], ""),
        ([""], ""),
        (["a"], "a"),
        (["ab", "ab", "ab"], "ab"),
        (["abc", "abcd", "ab"], "ab"),
        (["cir", "car"], "c"),
        (["ab", "a"], "a"),
    ]

    for i, (strs, expected) in enumerate(test_cases, 1):
        r1 = s.longestCommonPrefix(strs)
        r2 = s.longestCommonPrefix_horizontal(strs)
        assert r1 == expected, f"用例{i}纵向扫描失败: 期望'{expected}', 得到'{r1}'"
        assert r2 == expected, f"用例{i}横向扫描失败: 期望'{expected}', 得到'{r2}'"
        print(f"用例{i}: {strs} => '{r1}' ✓")
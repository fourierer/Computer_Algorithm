"""
1143.最长公共子序列
难度：中等
链接：https://leetcode.cn/problems/longest-common-subsequence/
"""
from typing import List


class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        m, n = len(text1), len(text2)
        # dp[i][j] 表示 text1[:i] 和 text2[:j] 的最长公共子序列长度
        # 尺寸 (m+1)×(n+1)：i 取 0..m，j 取 0..n
        # i=0 和 j=0 对应空串边界，+1 是为了容纳空串初始值，否则递推缺少初始值
        dp = [[0] * (n + 1) for _ in range(m + 1)]

        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if text1[i - 1] == text2[j - 1]:
                    # 末尾字符相同，可以加入公共子序列，长度 +1
                    dp[i][j] = dp[i - 1][j - 1] + 1
                else:
                    # 末尾字符不同，两者不可能同时出现在公共子序列中，至少要舍弃一个
                    # dp[i-1][j]：舍弃 text1[i-1]，用 text1[:i-1] 匹配 text2[:j]
                    # dp[i][j-1]：舍弃 text2[j-1]，用 text1[:i] 匹配 text2[:j-1]
                    # 取较大值即保留更长的子序列；dp[i-1][j-1] 不需单独考虑，已包含在两者中
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

        return dp[m][n]


class SolutionSubstring:
    def longestCommonSubstring(self, text1: str, text2: str) -> int:
        # 最长公共子串：与子序列的区别在于"子串必须连续"
        # dp[i][j] 表示以 text1[i-1] 和 text2[j-1] 结尾的最长公共子串长度
        m, n = len(text1), len(text2)
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        ans = 0  # 记录全局最大值（子串可以结束在任意位置，不像子序列固定在 dp[m][n]）

        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if text1[i - 1] == text2[j - 1]:
                    # 字符相同：在以 i-2, j-2 结尾的子串后接上这个字符，长度 +1
                    dp[i][j] = dp[i - 1][j - 1] + 1
                    ans = max(ans, dp[i][j])
                else:
                    # 字符不同：连续被打断，以这里结尾的公共子串长度为 0
                    # （区别于子序列的 max(dp[i-1][j], dp[i][j-1])）
                    dp[i][j] = 0

        return ans


if __name__ == "__main__":
    sub = Solution()
    sub_str = SolutionSubstring()

    # 测试用例：对比"最长公共子序列"与"最长公共子串"的差异
    # 子序列允许跳跃（不连续），子串必须连续
    cases = [
        # (text1, text2, 子序列期望, 子串期望)
        ("abcde", "ace", 3, 1),       # 子序列 ace(跳着取)，子串只有单字符 a/e
        ("abcdef", "abc", 3, 3),      # 公共部分 abc 连续，两者相同
        ("ababc", "bab", 3, 3),       # 子序列 bab，子串 bab 也连续
        ("programming", "gram", 4, 4),# 公共 gram 连续
        ("abcbdab", "bdcaba", 4, 2),  # 子序列 4，子串只 ab/bc=2
        ("abc", "abc", 3, 3),         # 完全相同
        ("aaaa", "aa", 2, 2),         # 公共 aa 连续
        ("abcde", "fgh", 0, 0),       # 无公共
        ("blue", "clues", 3, 3),      # 公共 lue 连续
        ("abmcd", "xmcy", 2, 2),      # 公共 mc 连续，两者相同
    ]

    print(f"{'text1':<12} {'text2':<12} {'子序列':<8} {'子串':<8} {'差异'}")
    print("-" * 55)
    all_ok = True
    for t1, t2, exp_seq, exp_sstr in cases:
        got_seq = sub.longestCommonSubsequence(t1, t2)
        got_sstr = sub_str.longestCommonSubstring(t1, t2)
        ok = (got_seq == exp_seq) and (got_sstr == exp_sstr)
        if not ok:
            all_ok = False
        diff = "不同" if got_seq != got_sstr else "相同"
        mark = " <-- 区别" if got_seq != got_sstr else ""
        status = "OK" if ok else "FAIL"
        print(f"{t1:<12} {t2:<12} {got_seq:<8} {got_sstr:<8} {diff}{mark}  [{status}]")

    print("-" * 55)
    print("ALL OK" if all_ok else "SOME FAILED")

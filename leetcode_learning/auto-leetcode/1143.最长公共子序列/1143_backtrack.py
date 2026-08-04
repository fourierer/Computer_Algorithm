"""
1143.最长公共子序列（带具体序列回溯）
难度：中等
链接：https://leetcode.cn/problems/longest-common-subsequence/
同时求最长公共子串及其具体内容
"""
from typing import List, Tuple


class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> Tuple[int, str]:
        # 同时返回 (长度, 具体子序列)
        m, n = len(text1), len(text2)
        dp = [[0] * (n + 1) for _ in range(m + 1)]

        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if text1[i - 1] == text2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1] + 1
                else:
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

        # 回溯 dp 表 reconstruct 出具体子序列
        # 从右下角 (m, n) 出发，逆推每一步的来源
        i, j = m, n
        seq = []  # 逆序收集字符
        while i > 0 and j > 0:
            if text1[i - 1] == text2[j - 1]:
                # 字符相同：这个字符在子序列中，加入结果
                seq.append(text1[i - 1])
                i -= 1
                j -= 1
            elif dp[i - 1][j] >= dp[i][j - 1]:
                # 来自上方：说明 text1[i-1] 未被选入，跳过
                i -= 1
            else:
                # 来自左方：说明 text2[j-1] 未被选入，跳过
                j -= 1
        # seq 是从后往前收集的，翻转得到正序子序列
        return dp[m][n], ''.join(reversed(seq))


class SolutionSubstring:
    def longestCommonSubstring(self, text1: str, text2: str) -> Tuple[int, str]:
        # 同时返回 (长度, 具体子串)
        m, n = len(text1), len(text2)
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        ans = 0
        end_i = 0  # 记录最长子串在 text1 中的结束位置

        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if text1[i - 1] == text2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1] + 1
                    if dp[i][j] > ans:
                        ans = dp[i][j]
                        end_i = i  # 记录结束位置（1-indexed）
                else:
                    dp[i][j] = 0

        # 子串连续，直接用结束位置和长度截取
        # end_i 是 1-indexed（dp 表的下标），对应 text1[end_i-1]
        # 长度 ans，起点 = end_i - ans（1-indexed），转 0-indexed 截取
        substring = text1[end_i - ans:end_i] if ans > 0 else ""
        return ans, substring


if __name__ == "__main__":
    sub = Solution()
    sub_str = SolutionSubstring()

    def is_subseq(s: str, t: str) -> bool:
        """校验 s 是否是 t 的子序列（按顺序出现，不要求连续）"""
        it = iter(t)
        return all(c in it for c in s)

    cases = [
        ("abcde", "ace"),
        ("abcdef", "abc"),
        ("abcbdab", "bdcaba"),
        ("abc", "abc"),
        ("aaaa", "aa"),
        ("abcde", "fgh"),
        ("blue", "clues"),
    ]

    print(f"{'text1':<10} {'text2':<10} | {'子序列长度':<8} {'子序列':<8} | {'子串长度':<8} {'子串':<8}")
    print("-" * 70)
    all_ok = True
    for t1, t2 in cases:
        seq_len, seq_str = sub.longestCommonSubsequence(t1, t2)
        sstr_len, sstr_str = sub_str.longestCommonSubstring(t1, t2)
        # 校验长度一致
        ok = (len(seq_str) == seq_len) and (len(sstr_str) == sstr_len)
        # 校验子串确实是两串的公共连续子串
        if sstr_len > 0:
            ok = ok and (sstr_str in t1) and (sstr_str in t2)
        # 校验子序列按顺序出现在两串中
        if seq_len > 0:
            ok = ok and is_subseq(seq_str, t1) and is_subseq(seq_str, t2)
        if not ok:
            all_ok = False
        print(f"{t1:<10} {t2:<10} | {seq_len:<8} {seq_str:<8} | {sstr_len:<8} {sstr_str:<8}")
    print("-" * 70)
    print("ALL OK" if all_ok else "SOME FAILED")

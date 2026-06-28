"""
131.分割回文串
难度：中等
链接：https://leetcode.cn/problems/palindrome-partitioning/
"""
from typing import List


class Solution:
    def partition(self, s: str) -> List[List[str]]:
        n = len(s)
        # ===== 预处理回文表：直接复用 5.最长回文子串 的 DP 代码 =====
        # dp[i][j] 表示 s[i..j] 是否为回文子串
        # 注意：必须以间隔 k 为外层循环，因为递推会用到 dp[i+1][j-1]
        dp = [[0] * n for _ in range(n)]
        for k in range(n):
            for i in range(n - k):
                j = i + k
                if k == 0:
                    dp[i][j] = 1
                elif k == 1:
                    dp[i][j] = (s[i] == s[j])
                else:
                    dp[i][j] = ((s[i] == s[j]) and (dp[i + 1][j - 1]))
                # 第 5 题在这里收集最长回文，131 题不需要，只需保留 dp 表

        # ===== 回溯：用 dp 表枚举所有分割方案 =====
        # start：当前要切的起点位置（前面 [0, start) 已切好）
        # path：已经切好的回文段列表
        # res：收集所有完整的分割方案
        res = []
        '''
        用 s = "aab" 走一遍：
        backtrack(start=0, path=[])
        ├─ end=0: dp[0][0]='a'回文 → path=['a'] → backtrack(1, ['a'])
        │   ├─ end=1: dp[1][1]='a'回文 → path=['a','a'] → backtrack(2, ['a','a'])
        │   │   └─ end=2: dp[2][2]='b'回文 → path=['a','a','b'] → backtrack(3)
        │   │       └─ start==n=3 ✓ → res=[['a','a','b']]
        │   └─ end=2: dp[1][2]='ab'非回文 → 跳过
        ├─ end=1: dp[0][1]='aa'回文 → path=['aa'] → backtrack(2, ['aa'])
        │   └─ end=2: dp[2][2]='b'回文 → path=['aa','b'] → backtrack(3)
        │       └─ start==n=3 ✓ → res=[['a','a','b'], ['aa','b']]
        └─ end=2: dp[0][2]='aab'非回文 → 跳过

        最终 res = [['a','a','b'], ['aa','b']]
        '''
        def backtrack(start: int, path: List[str]):
            # 起点已到末尾 → 整串切完了，收集一组方案
            if start == n:
                # path[:] 拷贝一份存入，否则后续 pop 会改掉 res 里的内容
                res.append(path[:])
                return
            # 尝试切 [start..end] 这一段，end 从 start 遍历到末尾
            for end in range(start, n):
                # 只有 s[start..end] 是回文时才切这一刀
                if dp[start][end]:
                    path.append(s[start:end + 1])  # 切下这一段，加入 path
                    backtrack(end + 1, path)        # 递归去切剩余部分 [end+1, n)
                    path.pop()                      # 回溯：撤销这一刀，尝试下一个 end

        backtrack(0, [])
        return res

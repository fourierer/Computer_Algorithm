"""
274.H指数
难度：中等
链接：https://leetcode.cn/problems/h-index/
"""



class Solution:
    def hIndex(self, citations: list[int]) -> int:
        # 从大到小排序，找最大的 h 使得前 h 篇引用次数都 >= h
        citations.sort(reverse=True)
        h = 0
        for i, c in enumerate(citations):
            if c >= i + 1:
                h = i + 1
            else:
                break
        return h


class SolutionCount:
    def hIndex(self, citations: list[int]) -> int:
        # 计数排序：h 指数不会超过论文数 n，引用次数 > n 的统一归到 counter[n]
        n = len(citations)
        counter = [0] * (n + 1)
        for c in citations:
            counter[min(c, n)] += 1

        total = 0  # 引用次数 >= i 的论文总数
        for i in range(n, -1, -1):
            total += counter[i]
            # 至少有 total 篇论文引用次数 >= i，且 total >= i
            if total >= i:
                return i
        return 0
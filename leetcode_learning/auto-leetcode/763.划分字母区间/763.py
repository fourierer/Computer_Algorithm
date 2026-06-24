"""
763.划分字母区间
难度：中等
链接：https://leetcode.cn/problems/partition-labels/
"""
from typing import List


class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        # 预处理：记录每个字母的最后一次出现位置
        # 一个片段的右边界必须覆盖片段内所有字母的最后一次出现
        last = {}
        for i, c in enumerate(s):
            last[c] = i

        res = []
        start = 0  # 当前段起点
        end = 0    # 当前段右边界（不断向右扩展）
        for i, c in enumerate(s):
            # 用当前字母的最后一次出现更新右边界
            end = max(end, last[c])
            # 扫描到右边界：当前段内所有字母的最后一次出现都已被覆盖
            # 可以在此切分，记录段长度并开始新段
            if i == end:
                res.append(end - start + 1)
                start = i + 1
        return res


class SolutionInterval:
    def partitionLabels(self, s: str) -> List[int]:
        # 区间合并视角：每个字母对应 [first, last] 区间
        # 相交区间必须合并到同一片段，输出各合并区间长度
        first, last = {}, {}
        for i, c in enumerate(s):
            if c not in first:
                first[c] = i
            last[c] = i

        # 按区间起点排序
        intervals = sorted((first[c], last[c]) for c in first)

        res = []
        cur_start, cur_end = intervals[0]
        for st, en in intervals[1:]:
            if st <= cur_end:
                # 相交，合并（扩展右端点）
                cur_end = max(cur_end, en)
            else:
                # 不相交，输出当前合并区间并开启新区间
                res.append(cur_end - cur_start + 1)
                cur_start, cur_end = st, en
        res.append(cur_end - cur_start + 1)
        return res

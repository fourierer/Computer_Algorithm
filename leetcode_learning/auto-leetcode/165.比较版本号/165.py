"""
165.比较版本号
难度：中等
链接：https://leetcode.cn/problems/compare-version-numbers/
"""


class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        v1 = version1.split('.')
        v2 = version2.split('.')
        # 取较长的长度，逐段比较，短的一方越界按 0 处理
        m, n = len(v1), len(v2)
        for i in range(max(m, n)):
            n1 = int(v1[i]) if i < m else 0
            n2 = int(v2[i]) if i < n else 0
            if n1 > n2:
                return 1
            elif n1 < n2:
                return -1
        return 0

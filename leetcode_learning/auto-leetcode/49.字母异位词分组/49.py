"""
49.字母异位词分组
难度：中等
链接：https://leetcode.cn/problems/group-anagrams/
"""

import collections
from typing import List


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        # defaultdict(list)：访问不存在的键时自动创建空列表作为默认值，避免 KeyError
        mp = collections.defaultdict(list)

        for st in strs:
            counts = [0] * 26
            for ch in st:
                # ord是python内置函数，用来得到字符的 ASCII / Unicode 编码值
                counts[ord(ch) - ord("a")] += 1
            # 需要将 list 转换成 tuple 才能进行哈希，因为python字典中的键要求是不可变的
            mp[tuple(counts)].append(st)

        return list(mp.values())


if __name__ == "__main__":
    sol = Solution()
    result = sol.groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"])
    # 按分组大小排序后比较
    assert sorted([sorted(g) for g in result]) == sorted([sorted(g) for g in [["bat"], ["nat", "tan"], ["ate", "eat", "tea"]]])
    assert sol.groupAnagrams([""]) == [[""]]
    assert sol.groupAnagrams(["a"]) == [["a"]]
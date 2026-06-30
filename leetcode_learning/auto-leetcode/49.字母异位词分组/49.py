"""
49.字母异位词分组
难度：中等
链接：https://leetcode.cn/problems/group-anagrams/
"""
from typing import List


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        # 用 26 维计数数组作为 key：字母组成相同的字符串计数数组相同 → 分到一组
        # tuple 化才能哈希（list 不可哈希不能做 dict 的键）
        count_dict = {}
        for st in strs:
            counts = [0] * 26
            for ch in st:
                index = ord(ch) - ord('a')
                counts[index] += 1
            # get(key, default)：键不存在时返回默认空列表，避免 KeyError
            cur_list = count_dict.get(tuple(counts), [])
            cur_list.append(st)
            count_dict[tuple(counts)] = cur_list

        return list(count_dict.values())


if __name__ == "__main__":
    sol = Solution()
    result = sol.groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"])
    assert sorted([sorted(g) for g in result]) == sorted([sorted(g) for g in [["bat"], ["nat", "tan"], ["ate", "eat", "tea"]]])
    assert sol.groupAnagrams([""]) == [[""]]
    assert sol.groupAnagrams(["a"]) == [["a"]]

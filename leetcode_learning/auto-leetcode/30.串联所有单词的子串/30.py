"""
30.串联所有单词的子串
难度：困难
链接：https://leetcode.cn/problems/substring-with-concatenation-of-all-words/
"""
from typing import List
from collections import Counter


class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        if not s or not words:
            return []

        word_len = len(words[0])
        total_len = word_len * len(words)
        n = len(s)

        if total_len > n:
            return []

        word_count = Counter(words)
        ans = []

        # 从每个偏移位置开始做滑动窗口
        for i in range(word_len):
            left = i
            window_count = Counter()
            # 每次取一个长度为 word_len 的单词
            for j in range(i, n - word_len + 1, word_len):
                word = s[j:j + word_len]
                if word not in word_count:
                    # 当前单词不在 words 中，清空窗口
                    window_count.clear()
                    left = j + word_len
                else:
                    window_count[word] += 1
                    # 窗口内该单词数量超出要求，左端点右移
                    while window_count[word] > word_count[word]:
                        left_word = s[left:left + word_len]
                        window_count[left_word] -= 1
                        left += word_len
                    # 窗口长度等于 words 总长度时，记录结果
                    if j + word_len - left == total_len:
                        ans.append(left)
                        # 左端点右移一个单词，继续检查
                        left_word = s[left:left + word_len]
                        window_count[left_word] -= 1
                        left += word_len

        return ans
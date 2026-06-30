"""
443.压缩字符串
难度：中等
链接：https://leetcode.cn/problems/string-compression/
"""
from typing import List


class Solution:
    def compress(self, chars: List[str]) -> int:
        # 核心逻辑与统计连续字符的写法一致（cur_char + cur_count 遍历）
        # 关键改动：原地写入 chars，而非新建 result 列表
        #          且长度为 1 的组只写字符不写计数（题目要求）
        n = len(chars)
        if n == 0:
            return 0

        write = 0              # 写指针：当前写入位置
        cur_char = chars[0]    # 当前连续段的字符
        cur_count = 1          # 当前连续段的计数

        for i in range(1, n + 1):
            # i == n 处理最后一组；字符不同则一段结束
            if i == n or chars[i] != cur_char:
                # 写入字符
                chars[write] = cur_char
                write += 1
                # 长度 > 1 才写计数（题目要求长度为 1 的组只写字符）
                if cur_count > 1:
                    # 多位数需逐位写入（如 12 → '1','2'）
                    for digit in str(cur_count):
                        chars[write] = digit
                        write += 1
                # 开始新的一段
                if i < n:
                    cur_char = chars[i]
                    cur_count = 1
            else:
                cur_count += 1

        return write

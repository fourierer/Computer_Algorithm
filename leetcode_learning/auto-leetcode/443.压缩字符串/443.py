"""
443.压缩字符串
难度：中等
链接：https://leetcode.cn/problems/string-compression/
"""
from typing import List


class Solution:
    def compress(self, chars: List[str]) -> int:
        # 借用统计连续字符的核心代码（cur_char + cur_count）
        # 唯一改动：count==1 只写字符，count>1 写"计数+字符"（题目要求）
        result = []
        cur_char = chars[0]
        cur_count = 1
        for i in range(1, len(chars)):
            if chars[i] == cur_char:
                cur_count += 1
            else:
                if cur_count == 1:
                    result.append(cur_char)
                else:
                    result.append(cur_char)
                    # extend+list 拆开多位数的每一位为独立字符元素
                    # 如 count=12 → list(str(12))=['1','2']
                    # 若用 append(str(12)) 会得到 ['b','12']（'12'长度为2，不符合单字符要求）
                    result.extend(list(str(cur_count)))
                cur_char = chars[i]
                cur_count = 1
        # 最后一段
        if cur_count == 1:
            result.append(cur_char)
        else:
            result.append(cur_char)
            # 同上：多位数需拆成独立字符
            result.extend(list(str(cur_count)))
        # 原地写回 chars
        chars[:] = result
        return len(result)

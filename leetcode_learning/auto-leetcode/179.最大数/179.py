"""
179.最大数
难度：中等
链接：https://leetcode.cn/problems/largest-number/
"""
from functools import cmp_to_key
from typing import List


class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        # 核心 trick：自定义排序，a+b > b+a 则 a 排前面
        strs = [str(num) for num in nums]

        # cmp 是二元比较函数：接收两个元素，返回 -1/0/1 表示先后顺序
        def cmp(a: str, b: str) -> int:
            if a + b > b + a:
                return -1  # a 应排在 b 前
            elif a + b < b + a:
                return 1
            else:
                return 0

        # 为何用 cmp_to_key 而非 key=lambda x: ...？
        # lambda x: 只能给每个元素独立算一个键（如长度、数值），用键本身的 < 排序
        # 但本题的比较依赖两两关系 a+b vs b+a，无法拆成"每个元素单独算一个键"
        # 如 3 和 30：3 应在 30 前（"330">"303"），但 3 和 34：34 应在 3 前（"343">"334"）
        # 同一个元素 3 相对不同元素先后不同 → 必须用二元 cmp 函数
        # cmp_to_key 把 cmp 包装成带 __lt__ 的对象，让 sort 能调用二元比较
        strs.sort(key=cmp_to_key(cmp))
        # 拼接后处理全零的情况（前导零）
        result = ''.join(strs)
        return '0' if result[0] == '0' else result


class SolutionBubble:
    def largestNumber(self, nums: List[int]) -> str:
        # 冒泡排序版：两层 for 循环，比较用 a+b vs b+a
        # 若 a+b < b+a，说明 a 应排在 b 后面 → 交换（大的往前冒泡）
        strs = [str(num) for num in nums]
        n = len(strs)
        for i in range(n):
            for j in range(n - 1):
                # 拼接后比较：若 strs[j]+strs[j+1] 字典序更小，则交换
                if strs[j] + strs[j + 1] < strs[j + 1] + strs[j]:
                    strs[j], strs[j + 1] = strs[j + 1], strs[j]
        result = ''.join(strs)
        return '0' if result[0] == '0' else result

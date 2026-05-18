"""
380.O(1)时间插入、删除和获取随机元素
难度：中等
链接：https://leetcode.cn/problems/insert-delete-getrandom-o1/
"""
import random


class RandomizedSet:

    def __init__(self):
        self.vals = []       # 数组：支持 O(1) 随机访问
        self.idx = {}        # 哈希表：值 → 数组索引，支持 O(1) 查找

    def insert(self, val: int) -> bool:
        if val in self.idx:
            return False
        self.vals.append(val)
        self.idx[val] = len(self.vals) - 1
        return True

    def remove(self, val: int) -> bool:
        if val not in self.idx:
            return False
        i = self.idx[val]
        last = self.vals[-1]
        # 将末尾元素移到要删除的位置，保持数组紧凑
        self.vals[i] = last
        self.idx[last] = i
        # 删除末尾元素和哈希表中 val 的记录
        self.vals.pop()
        del self.idx[val]
        return True

    def getRandom(self) -> int:
        return random.choice(self.vals)
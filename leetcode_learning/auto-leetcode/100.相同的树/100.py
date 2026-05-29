"""
100.相同的树
难度：简单
链接：https://leetcode.cn/problems/same-tree/
"""
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        # 两棵树同时为空，结构相同
        if not p and not q:
            return True
        # 一个为空一个不为空，结构不同
        elif not p or not q:
            return False
        # 节点值不同
        elif p.val != q.val:
            return False
        # 递归比较左子树和右子树
        else:
            return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)

"""
226.翻转二叉树
难度：简单
链接：https://leetcode.cn/problems/invert-binary-tree/
"""
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        # 空树直接返回
        if not root:
            return root

        # 递归翻转左右子树
        left = self.invertTree(root.left)
        right = self.invertTree(root.right)

        # 交换左右子树
        root.left, root.right = right, left

        return root

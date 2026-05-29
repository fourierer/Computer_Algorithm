"""
144.二叉树的前序遍历
难度：简单
链接：https://leetcode.cn/problems/binary-tree-preorder-traversal/
"""
from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        # 递归解法：根 → 左 → 右
        result = []

        def traverse(node):
            if not node:
                return
            result.append(node.val)
            traverse(node.left)
            traverse(node.right)

        traverse(root)
        return result


class SolutionIterative:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        # 迭代解法：用栈模拟，先右后左入栈（保证左子树先出栈）
        if not root:
            return []

        result = []
        stack = [root]

        while stack:
            node = stack.pop()
            result.append(node.val)
            # 先入右，后入左（栈后进先出，左子节点先被访问）
            if node.right:
                stack.append(node.right)
            if node.left:
                stack.append(node.left)

        return result

"""
145.二叉树的后序遍历
难度：简单
链接：https://leetcode.cn/problems/binary-tree-postorder-traversal/
"""
from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        # 递归解法：左 → 右 → 根
        result = []

        def traverse(node):
            if not node:
                return
            traverse(node.left)
            traverse(node.right)
            result.append(node.val)

        traverse(root)
        return result


class SolutionIterative:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        # 迭代解法：后序"左右根"的反序是"根右左"
        # 用类似前序的方式遍历（根右左），最后反转结果
        if not root:
            return []

        result = []
        stack = [root]

        while stack:
            node = stack.pop()
            result.append(node.val)
            # 先入左，后入右（栈后进先出，右子节点先被访问）
            if node.left:
                stack.append(node.left)
            if node.right:
                stack.append(node.right)

        # 反转得到后序遍历结果
        return result[::-1]

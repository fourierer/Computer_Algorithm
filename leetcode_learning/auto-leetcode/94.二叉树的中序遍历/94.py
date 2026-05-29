"""
94.二叉树的中序遍历
难度：简单
链接：https://leetcode.cn/problems/binary-tree-inorder-traversal/
"""
from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        # 递归解法：左 → 根 → 右
        result = []

        def traverse(node):
            if not node:
                return
            traverse(node.left)
            result.append(node.val)
            traverse(node.right)

        traverse(root)
        return result


class SolutionIterative:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        # 迭代解法：一路向左入栈，回溯时访问节点，再转向右子树
        result = []
        stack = []
        curr = root

        while curr or stack:
            # 一路向左，将路径上的节点全部入栈
            while curr:
                stack.append(curr)
                curr = curr.left

            # 弹出栈顶节点并访问
            curr = stack.pop()
            result.append(curr.val)

            # 转向右子树
            curr = curr.right

        return result

"""
114.二叉树展开为链表
难度：中等
链接：https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/
"""
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        # 原地算法 O(1) 空间：对每个节点，将左子树的最右节点接到原右子树
        curr = root

        while curr:
            if curr.left:
                # 找到左子树的最右节点（前驱节点）
                predecessor = curr.left
                while predecessor.right:
                    predecessor = predecessor.right

                # 将原右子树接到前驱节点的 right
                predecessor.right = curr.right

                # 将左子树移到 right，left 置空
                curr.right = curr.left
                curr.left = None

            # 继续处理下一个节点
            curr = curr.right


class SolutionRecursive:
    def flatten(self, root: Optional[TreeNode]) -> None:
        # 递归解法：后序遍历变体，先展开左右子树，再拼接
        if not root:
            return

        # 递归展开左右子树
        self.flatten(root.left)
        self.flatten(root.right)

        # 保存原右子树
        right = root.right

        # 将左子树移到 right
        root.right = root.left
        root.left = None

        # 找到新 right 链表的末尾，接上原右子树
        curr = root
        while curr.right:
            curr = curr.right
        curr.right = right


class SolutionIterative:
    def flatten(self, root: Optional[TreeNode]) -> None:
        # 迭代解法：用栈模拟先序遍历，记录顺序后重新连接
        if not root:
            return

        stack = [root]
        prev = None

        while stack:
            curr = stack.pop()

            if prev:
                prev.left = None
                prev.right = curr

            # 先入右，后入左（保证左子树先出栈）
            if curr.right:
                stack.append(curr.right)
            if curr.left:
                stack.append(curr.left)

            prev = curr

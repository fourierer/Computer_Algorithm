"""
101.对称二叉树
难度：简单
链接：https://leetcode.cn/problems/symmetric-tree/
"""
from collections import deque
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        # 比较左子树和右子树是否互为镜像
        return self.check(root.left, root.right)

    def check(self, p, q):
        # 两棵树同时为空，结构相同
        if not p and not q:
            return True
        # 一个为空一个不为空，结构不同
        if not p or not q:
            return False
        # 值相等 且 镜像子树递归比较
        return p.val == q.val and self.check(p.left, q.right) and self.check(p.right, q.left)


class SolutionBFS:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        # 使用队列，每次成对取出节点按镜像顺序比较
        queue = deque([(root.left, root.right)])

        while queue:
            p, q = queue.popleft()

            # 都为空，继续比较下一对
            if not p and not q:
                continue
            # 一个为空或值不同，不对称
            if not p or not q or p.val != q.val:
                return False

            # 镜像顺序入队：左的左 vs 右的右，左的右 vs 右的左
            queue.append((p.left, q.right))
            queue.append((p.right, q.left))

        return True

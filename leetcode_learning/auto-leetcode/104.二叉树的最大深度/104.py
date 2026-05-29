"""
104.二叉树的最大深度
难度：简单
链接：https://leetcode.cn/problems/maximum-depth-of-binary-tree/
"""
from collections import deque
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        # DFS 递归：树的深度 = max(左子树深度, 右子树深度) + 1
        if root is None:
            return 0
        left_depth = self.maxDepth(root.left)
        right_depth = self.maxDepth(root.right)
        return max(left_depth, right_depth) + 1


class SolutionBFS:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        # BFS 层序遍历：每遍历完一层，深度加 1
        if root is None:
            return 0

        queue = deque([root])
        depth = 0

        while queue:
            # 当前层的节点数
            level_size = len(queue)
            # 将当前层的所有节点弹出，并把子节点加入队列
            for _ in range(level_size):
                node = queue.popleft()
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            depth += 1

        return depth

"""
102.二叉树的层序遍历
难度：中等
链接：https://leetcode.cn/problems/binary-tree-level-order-traversal/
"""
from collections import deque
from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        result = []
        if not root:
            return result

        # BFS 层序遍历：队列中始终存储当前层的所有节点
        queue = deque([root])

        while queue:
            # 必须在循环开始时记录当前层节点数，
            # 因为处理过程中队列长度会变化（子节点不断入队）
            level_size = len(queue)
            level = []

            for i in range(level_size):
                node = queue.popleft()
                level.append(node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)

            result.append(level)

        return result
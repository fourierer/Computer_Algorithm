"""
199.二叉树的右视图
难度：中等
链接：https://leetcode.cn/problems/binary-tree-right-side-view/
"""
from collections import deque
from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        result = []
        if not root:
            return result

        # BFS 层序遍历：队列中始终存储当前层的所有节点
        queue = deque([root])

        while queue:
            # 当前层的节点数量，用于控制逐层遍历
            level_size = len(queue)

            for i in range(level_size):
                node = queue.popleft()
                # 每层最后一个节点即为右视图所见节点
                if i == level_size - 1:
                    result.append(node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)

        return result
"""
117.填充每个节点的下一个右侧节点指针 II
难度：中等
链接：https://leetcode.cn/problems/populating-next-right-pointers-in-each-node-ii/
"""
from collections import deque
from typing import Optional


class Node:
    def __init__(self, val: int = 0, left: 'Node' = None,
                 right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next


class Solution:
    def connect(self, root: Optional[Node]) -> Optional[Node]:
        # 利用当前层的 next 链表遍历，同时为下一层建立 next 链表
        curr = root

        while curr:
            # dummy 作为下一层的哑头节点
            dummy = Node(0)
            prev = dummy

            # 遍历当前层的所有节点
            while curr:
                if curr.left:
                    prev.next = curr.left
                    prev = prev.next
                if curr.right:
                    prev.next = curr.right
                    prev = prev.next
                curr = curr.next

            # 进入下一层
            curr = dummy.next

        return root


class SolutionBFS:
    def connect(self, root: Optional[Node]) -> Optional[Node]:
        # BFS 层序遍历，每层内连接 next 指针
        if not root:
            return None

        queue = deque([root])

        while queue:
            level_size = len(queue)
            prev = None

            for _ in range(level_size):
                node = queue.popleft()
                if prev:
                    prev.next = node
                prev = node

                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)

        return root

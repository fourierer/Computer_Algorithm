"""
106.从中序与后序遍历序列构造二叉树
难度：中等
链接：https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
"""
from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        # 构造哈希映射，O(1) 定位中序遍历中根节点的位置
        index = {val: i for i, val in enumerate(inorder)}

        def build(in_l: int, in_r: int, post_l: int, post_r: int) -> Optional[TreeNode]:
            if in_l > in_r:
                return None

            # 后序遍历的最后一个节点就是当前子树的根节点
            root_val = postorder[post_r]
            # 在中序遍历中定位根节点位置
            in_root = index[root_val]

            root = TreeNode(root_val)

            # 左子树的节点数目 = 中序遍历中根节点左边的元素个数
            size_left = in_root - in_l

            # 递归构建左子树
            root.left = build(in_l, in_root - 1, post_l, post_l + size_left - 1)
            # 递归构建右子树
            root.right = build(in_root + 1, in_r, post_l + size_left, post_r - 1)

            return root

        n = len(inorder)
        return build(0, n - 1, 0, n - 1)

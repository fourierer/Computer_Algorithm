"""
105.从前序和中序遍历序列构造二叉树
难度：中等
链接：https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
"""
from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        # 构造哈希映射，O(1) 定位中序遍历中根节点的位置
        index = {val: i for i, val in enumerate(inorder)}

        def myBuildTree(preorder_left: int, preorder_right: int,
                        inorder_left: int, inorder_right: int) -> Optional[TreeNode]:
            if preorder_left > preorder_right:
                return None

            # 前序遍历的第一个节点就是当前子树的根节点
            preorder_root = preorder_left
            # 在中序遍历中定位根节点位置
            inorder_root = index[preorder[preorder_root]]

            root = TreeNode(preorder[preorder_root])

            # 左子树的节点数目 = 中序遍历中根节点左边的元素个数
            size_left_subtree = inorder_root - inorder_left

            # 递归构建左子树
            root.left = myBuildTree(
                preorder_left + 1, preorder_left + size_left_subtree,
                inorder_left, inorder_root - 1
            )
            # 递归构建右子树
            root.right = myBuildTree(
                preorder_left + size_left_subtree + 1, preorder_right,
                inorder_root + 1, inorder_right
            )
            return root

        n = len(preorder)
        return myBuildTree(0, n - 1, 0, n - 1)

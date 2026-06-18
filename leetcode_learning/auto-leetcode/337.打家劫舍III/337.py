"""
337.打家劫舍III
难度：中等
链接：https://leetcode.cn/problems/house-robber-iii/
"""
from functools import lru_cache
from typing import Optional, Tuple


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def rob(self, root: Optional[TreeNode]) -> int:
        # 树形 DP：每个节点返回 (偷该节点的子树最大值, 不偷该节点的子树最大值)
        # 父节点据此推导，后序遍历自底向上汇总，无需哈希缓存
        def dfs(node: Optional[TreeNode]) -> Tuple[int, int]:
            # 空节点：偷和不偷都是 0
            if not node:
                return (0, 0)
            left_rob, left_not = dfs(node.left)
            right_rob, right_not = dfs(node.right)
            # 偷当前节点：左右子节点都不能偷 → node.val + left_not + right_not
            rob = node.val + left_not + right_not
            # 不偷当前节点：左右子节点各自取偷/不偷的较大值相加
            not_rob = max(left_rob, left_not) + max(right_rob, right_not)
            return (rob, not_rob)

        root_rob, root_not = dfs(root)
        # 根节点可偷可不偷，取较大值
        return max(root_rob, root_not)


class SolutionMemo:
    def rob(self, root: Optional[TreeNode]) -> int:
        # 记忆化版本：对节点缓存“偷/不偷当前节点”两种情况的子树最大值
        # lru_cache 需要节点可哈希，TreeNode 默认按 id 哈希，可行
        @lru_cache(None)
        def dfs(node: Optional[TreeNode], steal: bool) -> int:
            if not node:
                return 0
            if steal:
                # 偷当前节点：金额 = node.val + 左右子节点都“不偷”的最大值
                return node.val + dfs(node.left, False) + dfs(node.right, False)
            else:
                # 不偷当前节点：左右子节点各自“偷/不偷”取较大值
                left = max(dfs(node.left, True), dfs(node.left, False))
                right = max(dfs(node.right, True), dfs(node.right, False))
                return left + right

        # 根节点可偷可不偷，取较大值
        return max(dfs(root, True), dfs(root, False))

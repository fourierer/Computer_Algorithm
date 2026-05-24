"""
141.环形链表
难度：简单
链接：https://leetcode.cn/problems/linked-list-cycle/
"""


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        # 解法一：快慢指针，O(1)空间
        slow = head
        fast = head

        while fast and fast.next:
            # 慢指针走一步，快指针走两步
            slow = slow.next
            fast = fast.next.next
            # 快慢指针相遇，说明有环
            if slow is fast:
                return True

        return False

    def hasCycle_hash(self, head: ListNode) -> bool:
        # 解法二：哈希集合，O(n)空间
        seen = set()
        curr = head

        while curr:
            # 节点已在集合中，说明有环
            if curr in seen:
                return True
            seen.add(curr)
            curr = curr.next

        return False


if __name__ == "__main__":
    # 构造有环链表：3 -> 2 -> 0 -> -4 -> 2（环）
    node1 = ListNode(3)
    node2 = ListNode(2)
    node3 = ListNode(0)
    node4 = ListNode(-4)
    node1.next = node2
    node2.next = node3
    node3.next = node4
    node4.next = node2
    assert Solution().hasCycle(node1) == True
    assert Solution().hasCycle_hash(node1) == True

    # 无环链表：1 -> 2 -> None
    node1 = ListNode(1)
    node2 = ListNode(2)
    node1.next = node2
    assert Solution().hasCycle(node1) == False
    assert Solution().hasCycle_hash(node1) == False
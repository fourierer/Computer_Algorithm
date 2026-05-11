"""
LeetCode 19.删除链表的倒数第N个结点
难度：中等
标签：链表、双指针
"""

from typing import Optional
    

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val: int = 0, next: Optional['ListNode'] = None):
        self.val = val
        self.next = next

    def to_list(self) -> list[int]:
        """链表转列表，方便测试"""
        result = []
        node = self
        while node:
            result.append(node.val)
            node = node.next
        return result


class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        """快慢指针 + 虚拟头结点，一趟扫描"""
        # 虚拟头结点：统一处理头结点被删除的情况
        dummy = ListNode(0, head)
        fast = slow = dummy

        # 快指针先走 n+1 步，这样慢指针最终停在待删除结点的【前驱】
        for _ in range(n + 1):
            fast = fast.next

        # 快慢同步前进，fast 到末尾时 slow 恰好在倒数第 n+1 个位置
        while fast:
            fast = fast.next
            slow = slow.next

        # 删除倒数第 n 个结点
        slow.next = slow.next.next

        return dummy.next

    def removeNthFromEnd_two_pass(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        """两次遍历：先求长度，再定位删除"""
        # 第一次遍历：求链表长度
        length = 0
        cur = head
        while cur:
            length += 1
            cur = cur.next

        # 虚拟头结点
        dummy = ListNode(0, head)
        cur = dummy

        # 第二次遍历：走到倒数第 n+1 个结点（即待删除的前驱）
        for _ in range(length - n):
            cur = cur.next

        cur.next = cur.next.next
        return dummy.next


def build_list(vals: list[int]) -> Optional[ListNode]:
    """从列表构建链表"""
    if not vals:
        return None
    head = ListNode(vals[0])
    cur = head
    for v in vals[1:]:
        cur.next = ListNode(v)
        cur = cur.next
    return head


if __name__ == "__main__":
    s = Solution()

    # 示例 1：删除中间结点
    head1 = build_list([1, 2, 3, 4, 5])
    result1 = s.removeNthFromEnd(head1, 2)
    assert result1.to_list() == [1, 2, 3, 5], f"Failed: {result1.to_list()}"

    # 示例 2：删除唯一结点
    head2 = build_list([1])
    result2 = s.removeNthFromEnd(head2, 1)
    assert result2 is None

    # 示例 3：删除尾结点
    head3 = build_list([1, 2])
    result3 = s.removeNthFromEnd(head3, 1)
    assert result3.to_list() == [1]

    # 边界：删除头结点
    head4 = build_list([1, 2, 3])
    result4 = s.removeNthFromEnd(head4, 3)
    assert result4.to_list() == [2, 3]

    # 两次遍历法同样验证
    head5 = build_list([1, 2, 3, 4, 5])
    result5 = s.removeNthFromEnd_two_pass(head5, 2)
    assert result5.to_list() == [1, 2, 3, 5]

    print("All tests passed!")

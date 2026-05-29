"""
86.分隔链表
难度：中等
链接：https://leetcode.cn/problems/partition-list/
"""


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        # 两个哑节点，分别作为小于链表和大于等于链表的虚拟头
        before_head = ListNode(0)
        after_head = ListNode(0)

        before = before_head
        after = after_head

        # 遍历原链表，按条件分配到两个子链表
        while head:
            if head.val < x:
                before.next = head
                before = before.next
            else:
                after.next = head
                after = after.next
            head = head.next

        # 断开大于等于链表的尾部，防止成环
        after.next = None

        # 拼接：小于链表的尾部连接大于等于链表的头部
        before.next = after_head.next

        return before_head.next
